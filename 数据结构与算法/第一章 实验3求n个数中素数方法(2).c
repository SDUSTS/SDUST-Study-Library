#include <stdio.h>
#include <math.h>
int main(){
    int i,n; 
    scanf("%d",&n);
	for(i=2;i<n;i++){
		if(isss(i)==1){
			printf("%d ",i);
		}		
	}
	return 0;
}
int isss(int m)
{
 // ���������m 
    int i;  // ѭ������
    int k;  // m ��ƽ���� 
    // ��ƽ������ע��sqrt()�Ĳ���Ϊ double ���ͣ�����Ҫǿ��ת��m������ 
    k=(int)sqrt( (double)m );
    for(i=2;i<=k;i++)
        if(m%i==0)
            break;
    // ����������ѭ������ômΪ����
    // ע�����һ��ѭ������ִ��i++����ʱ i=k+1��������i>k 
    if(i>k)
        return 1;
    else
		return 0;
}
