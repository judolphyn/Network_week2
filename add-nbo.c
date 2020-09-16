#include <stdio.h>
#include <stdint.h>

uint32_t ntohl (uint32_t n){
	return (n<<24) | ((n<<8)&0xff0000) | ((n>>8)&0xff00) | (n>>24) ;
}	

int main(int argc, char *argv[]){

	FILE *fp1 = fopen(argv[1],"r");
	FILE *fp2 = fopen(argv[2],"r");	
	uint32_t a,b;

	if(fread(&a,sizeof(a),1,fp1)<1){
		printf("file1 read error!\n");
		return -1;
	}
	if(fread(&b,sizeof(b),1,fp2)<1){
		printf("file2 read error!\n");
		return -1;
	}
	a = ntohl(a);
	b = ntohl(b);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,a+b,a+b);
	return 0;
}
