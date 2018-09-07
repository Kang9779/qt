in=fopen('Normal_v2.txt','r');
dataformat='%f %f %f';
datasize=[3 Inf];
data=fscanf(in,dataformat,datasize);
data=data'*1e-6;
fclose(in);
new=fopen('Normal_v2.txt','w');
for i=1:20001
    fprintf(new,'%s %.4f %.4f\n',time{i},data(i,2),data(i,3));
end
fclose(new);