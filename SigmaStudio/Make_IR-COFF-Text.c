/* 
 * Make an text file for SigmaStudio from the .RAW Impluse Responsefile
 *  2023 Copyright (c) CyberPit
 *  All Rights Reserved.
 * version 0.1 NonRelased
 */

#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;

union DataArias
{
	unsigned char buffer[4];
	signed int sampledata;
};


int main(int argc,char  **argv)
{
	union DataArias data;
	char infilename[256];
	char outfilename[256];
	signed int	value;
	int	loop;
	float cofficent;
	FILE *ifp, *ofp;
	
	if (argc < 2)
		printf("\nUsage make_512FIR-COFF-TABLE  infname outfname");
		
	/* Open IR FIle */
	//gets(filename);
//	sprintf(filename,  "%s.row", argv[1]); //ファイルネームを入力する
	ifp = fopen(argv[1], "rb");
	ofp = fopen(argv[2], "wt");
	
//	printf("Size=%d\n", sizeof(int));
for(loop =0; loop<=512; loop++)
	{
	data.buffer[2] = fgetc(ifp);
	data.buffer[2] = fgetc(ifp);
	data.buffer[3] = fgetc(ifp);
	data.buffer[0] = 0;
	value = data.sampledata;
	cofficent = (float)value/(float)0x7fffffff;
	printf("\n%02x %02x %02x %02d %010d/%d %f",data.buffer[3] ,data.buffer[2],data.buffer[1], data.buffer[0],value, 0x7FFFFFFF, cofficent);
	fprintf(ofp, "%f\n",cofficent);
	}
	/* waveファイルをクローズ */
	fclose(ifp);
fclose(ofp);
	return 0;
}
