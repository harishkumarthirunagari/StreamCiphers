#include <stdio.h>


int main()
{

FILE *lsofFile_p = popen("openssl enc -rc4 -a -salt -base64 -in test.txt -out decrypt.txt", "r");


  if (!lsofFile_p)
  {
    return -1;
  }


char buffer[1024];
 while (fgets(buffer, sizeof(buffer), lsofFile_p) != NULL)
{
    printf("encrypted text");
    printf("%s",buffer);   
}



FILE *lsofFiledec_p = popen("openssl enc -rc4 -d -a -salt -base64 -in decrypt.txt", "r");

  if (!lsofFiledec_p)
  {
    return -1;
  }
 char bufferdec[1024];
char *linedec_p;  


char bufferb[1024];

FILE *lsofFile = popen("cat decrypt.txt", "r");
 while (fgets(bufferb, sizeof(bufferb), lsofFile) != NULL)
{
    printf("encrypted text:::->");
    printf("%s",bufferb);   
}



  while (fgets(bufferdec, sizeof(bufferdec), lsofFiledec_p) != NULL)
 {
    printf("decrypted text::->");
    printf("%s",bufferdec);
 }


return 0;
}