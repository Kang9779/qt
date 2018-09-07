#include "can_recv_send.h"
#include <QMutex>       //线程加锁保护

#define CAN_BITRATE "/sbin/ip link set can0 type can bitrate 250000"
#define CAN_OPEN "ifconfig can0 up"
#define CAN_CLOSE "ifconfig can0 down"

QMutex mutex;

int j = 0;              //返回数据
int sum = 1;
int sum_right = 1;

void set_bitrate(void){     //设置波特率
    system(CAN_CLOSE);
    system(CAN_BITRATE);
    system(CAN_OPEN);
}

#define errout(_s) fprintf(stderr, "error class: %s\n", (_s))
#define errcode(_d) fprintf(stderr, "error code: %02x\n", (_d))

static void handle_err_frame(const struct can_frame *fr)
{
    if (fr->can_id & CAN_ERR_TX_TIMEOUT) {
        errout("CAN_ERR_TX_TIMEOUT");
    }
    if (fr->can_id & CAN_ERR_LOSTARB) {
        errout("CAN_ERR_LOSTARB");
        errcode(fr->data[0]);
    }
    if (fr->can_id & CAN_ERR_CRTL) {
        errout("CAN_ERR_CRTL");
        errcode(fr->data[1]);
    }
    if (fr->can_id & CAN_ERR_PROT) {
        errout("CAN_ERR_PROT");
        errcode(fr->data[2]);
        errcode(fr->data[3]);
    }
    if (fr->can_id & CAN_ERR_TRX) {
        errout("CAN_ERR_TRX");
        errcode(fr->data[4]);
    }
    if (fr->can_id & CAN_ERR_ACK) {
        errout("CAN_ERR_ACK");
    }
    if (fr->can_id & CAN_ERR_BUSOFF) {
        errout("CAN_ERR_BUSOFF");
    }
    if (fr->can_id & CAN_ERR_BUSERROR) {
        errout("CAN_ERR_BUSERROR");
    }
    if (fr->can_id & CAN_ERR_RESTARTED) {
        errout("CAN_ERR_RESTARTED");
    }
}

#define myerr(str) fprintf(stderr, "%s, %s, %d: %s\n", __FILE__, __func__, __LINE__, str)

#if 1  // 一个滤波器最多设置18个id
    /* can receive data function */
    int can_recv(struct can_frame frame[])
    {
        /* can通信的初始化 */
        int s=0;
        unsigned long nbytes = 0;
        struct sockaddr_can addr;	//can
        struct ifreq ifr;
        struct can_filter rfilter[14];	//过滤规则的结构体

        if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)	//创建套接字
        {
            perror("Error while opening socket");
            //return -1;
        }


        strncpy(ifr.ifr_name, "can0", sizeof(ifr.ifr_name)-1);
        ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';
        ioctl(s, SIOCGIFINDEX, &ifr);	//指定can0设备
        addr.can_family = AF_CAN;	//这两行必须有
        addr.can_ifindex =0;

        if((bind(s, (struct sockaddr *)&addr, sizeof(addr))) < 0)       //绑定
        {
            perror("Error in socket bind");
            //return -2;
        }

     /*只有扩展帧能通过，CAN_SFF_MASK 是标准帧，
     * CAN_SFF_MASK & CAN_EFF_MASK, 都能通过。
     * #define CAN_EFF_MASK 0x1FFFFFFFU
     */
        rfilter[0].can_id = 0x18FFFEF0;                      //发动机工作时间和总里程
        rfilter[0].can_mask = CAN_EFF_MASK;
        rfilter[1].can_id = 0x18FFFDF0;                      //系统电压等
        rfilter[1].can_mask = CAN_EFF_MASK;
        rfilter[2].can_id = 0x18FF0803;                      //米计里程
        rfilter[2].can_mask = CAN_EFF_MASK;
        rfilter[3].can_id = 0x18FF1003;                      //卸粮筒等
        rfilter[3].can_mask = CAN_EFF_MASK;
        rfilter[4].can_id = 0x18FF1103;                      //电磁阀等
        rfilter[4].can_mask = CAN_EFF_MASK;
        rfilter[5].can_id = 0x18FF1405;                      //备用
        rfilter[5].can_mask = CAN_EFF_MASK;
        rfilter[6].can_id = 0x18FF1607;                      //粮食干重
        rfilter[6].can_mask = CAN_EFF_MASK;
        rfilter[7].can_id = 0x18FF1707;                      //升运器转速
        rfilter[7].can_mask = CAN_EFF_MASK;
        rfilter[8].can_id = 0x18FF1909;                      //空、前进、倒档
        rfilter[8].can_mask = CAN_EFF_MASK;
        rfilter[9].can_id = 0x18FF2011;                      //抛撒器角度和切碎器转速
        rfilter[9].can_mask = CAN_EFF_MASK;
        rfilter[10].can_id = 0x18FF2111;                     //备用
        rfilter[10].can_mask = CAN_EFF_MASK;
        rfilter[11].can_id = 0x18FF2313;                     //仿形高度等
        rfilter[11].can_mask = CAN_EFF_MASK;
        rfilter[12].can_id = 0x18FF2413;                     //割宽
        rfilter[12].can_mask = CAN_EFF_MASK;
        rfilter[13].can_id = 0x18FF2817;                     //备用
        rfilter[13].can_mask = CAN_EFF_MASK;

        setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));	//设置过滤规则
        nbytes = read(s, frame, sizeof(*frame));
        close(s);
        return(nbytes);
    }

#endif


    int can_recv2(struct can_frame frame[])
    {
        /* can通信的初始化 */
        int s=0;
        unsigned long nbytes = 0;
        struct sockaddr_can addr;	//can
        struct ifreq ifr;
        struct can_filter rfilter[14];	//过滤规则的结构体
        if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)	//创建套接字
        {
            perror("Error while opening socket");
            //return -1;
        }
        strncpy(ifr.ifr_name, "can0", sizeof(ifr.ifr_name)-1);
        ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';
        ioctl(s, SIOCGIFINDEX, &ifr);	//指定can0设备

        addr.can_family = AF_CAN;	//这两行必须有
        addr.can_ifindex =0;

        if((bind(s, (struct sockaddr *)&addr, sizeof(addr))) < 0)       //绑定
        {
            perror("Error in socket bind");
            //return -2;
        }

        /*只有扩展帧能通过，CAN_SFF_MASK 是标准帧，
         * CAN_SFF_MASK & CAN_EFF_MASK, 都能通过。
         */
        rfilter[0].can_id = 0x18FF1203;                     //复脱器转速   割刀频率等
        rfilter[0].can_mask = CAN_EFF_MASK;
        rfilter[1].can_id = 0x18FF1305;                     //清选风扇
        rfilter[1].can_mask = CAN_EFF_MASK;
        rfilter[2].can_id = 0x18FF1809;                     //损失率和含杂率
        rfilter[2].can_mask = CAN_EFF_MASK;
        rfilter[3].can_id = 0x18FF2515;                     //拨禾轮转速
        rfilter[3].can_mask = CAN_EFF_MASK;
        rfilter[4].can_id = 0x18FF2913;                     //行驶速度
        rfilter[4].can_mask = CAN_EFF_MASK;
        rfilter[5].can_id = 0x18FF2717;                     //轴流滚筒转矩
        rfilter[5].can_mask = CAN_EFF_MASK;
        rfilter[6].can_id = 0x18FEEE00;                     //发动机冷却水温
        rfilter[6].can_mask = CAN_EFF_MASK;
        rfilter[7].can_id = 0x18FEEF00;                     //发动机油压力
        rfilter[7].can_mask = CAN_EFF_MASK;
        rfilter[8].can_id = 0x18FEF700;                     //系统电压
        rfilter[8].can_mask = CAN_EFF_MASK;
        rfilter[9].can_id = 0x18FF0903;                     //前后马达转速
        rfilter[9].can_mask = CAN_EFF_MASK;
        rfilter[10].can_id = 0x18FF1507;                    //含水率等
        rfilter[10].can_mask = CAN_EFF_MASK;
        rfilter[11].can_id = 0x0CF00400 | CAN_EFF_FLAG;     //扩展帧，发动机转速
        rfilter[11].can_mask = 0xFFF;
        rfilter[12].can_id = 0x18FF2615;                    //喂入量
        rfilter[12].can_mask = CAN_EFF_MASK;
        rfilter[13].can_id = 0x18FF2213;                    //导航辅助驾驶调节
        rfilter[13].can_mask = CAN_EFF_MASK;

        setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));	//设置过滤规则
        nbytes = read(s, frame, sizeof(*frame));
        close(s);
        return(nbytes);
    }

    /* can send data function */
    //#define CAN_EFF_FLAG 0x80000000U
    void can_send(char data[])
    {
        QMutexLocker lock(&mutex);		//加锁，防止竞争
        char data7[64]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
                        25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,
                        46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64};

        int s = 0, nbytes= 0;

        struct sockaddr_can addr;
        struct ifreq ifr;		//s,addr,ifr都是为了将嵌套字和can接口连接
        struct can_frame frame;	//存储数据信息

        s = socket(PF_CAN,SOCK_RAW,CAN_RAW);	//创建一个套接字

        strncpy(ifr.ifr_name,"can0", sizeof(ifr.ifr_name)-1);
        ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';
        ioctl(s,SIOCGIFINDEX,&ifr);			//指定CAN0设备,得到索引

        addr.can_family = AF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;
        bind(s,(struct sockaddr*)&addr,sizeof(addr));//将套接字与can0设备连接在一起

        frame.can_id = CAN_EFF_FLAG|0x1c1f8828;

        frame.can_dlc = 8;

        for(int i = 0; i<7; i++)
        {
            frame.data[i] = data[i];
        }

        frame.data[7] = data7[j];

        j++;

        if(j%64 == 0)
        {
            j = 0;
        }
        setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
        nbytes = write(s, &frame, sizeof(frame));
        close(s);
    }


    //#define CAN_EFF_FLAG 0x80000000U
    void can_send1(QByteArray data ,int id)
    {
        QMutexLocker lock(&mutex);		//加锁，防止竞争
        int s = 0, nbytes= 0;
        struct sockaddr_can addr;
        struct ifreq ifr;		//s,addr,ifr都是为了将嵌套字和can接口连接
        struct can_frame frame;	//存储数据信息

        s = socket(PF_CAN,SOCK_RAW,CAN_RAW);	//创建一个套接字

        strncpy(ifr.ifr_name,"can0", sizeof(ifr.ifr_name)-1);
        ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';
        ioctl(s,SIOCGIFINDEX,&ifr);			//指定CAN0设备,得到索引

        addr.can_family = AF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;
        bind(s,(struct sockaddr*)&addr,sizeof(addr));//将套接字与can0设备连接在一起

        frame.can_id = CAN_EFF_FLAG| id;
        frame.can_dlc = 8;

        for(int i = 0; i<8; i++)
        {
            frame.data[i] = data.at(i);
        }

        setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
        nbytes = write(s, &frame, sizeof(frame));
        close(s);
    }
