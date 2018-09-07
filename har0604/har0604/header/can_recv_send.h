#ifndef CAN_RECV_SEND
#define CAN_RECV_SEND

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ioctl.h>	//这四条是can通信的头文件
#include <net/if.h>
#include <arpa/inet.h>
#include <linux/socket.h>
#include <linux/can/error.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
/* linux 文件的读写头文件 */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QByteArray>

#ifndef PF_CAN			//条件编译
#define PF_CAN 29
#endif

#ifndef AF_CAN
#define AF_CAN PF_CAN
#define CAN_EFF_FLAG 0x80000000U	//扩展帧的标识
#endif

extern int can_recv(can_frame frame[]);
extern int can_recv2(can_frame frame[]);
extern void can_send(char data[]);
extern void can_send1(QByteArray data,int id);
extern void set_bitrate(void);


/*control setting*/
static int clear_meter ;
static int reset_cutheight;
static int control_unloader;
static int auto_loader;
static int auto_cutheight;
static int reset_weight;
static int set_alarm;

static int reelSpeed;          //拨禾轮转速
static int cutterHz;              //割刀频率
static int feedAugerSpeed;      //搅龙转速



/*parameter setting*/

static int rsls;
static int concaveclset;
static float le;
static int pfh;
static int cutx;
static int cutn;
static int rollerSpeed;
static int draughtFanSpeed;
static int sortingScreenUp;
static int sortingScreenDown;
static int sortingScreenTail;


static int cuttermode;        //Combobox
static int grainkd = 0;       //Combobox


#endif // CAN_RECV_SEND

