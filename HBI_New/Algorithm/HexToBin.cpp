#include <stdio.h>
#include <stdlib.h>
char* HexToBinary(char * array)
{
	char * originArray = array;

	//获取传过来的字符数组的长度
	int originalLength = 0;
	while (*array)
	{
		originalLength++;
		array++;
	}

	int i = 0;
	int newLength = originalLength * 4;//新的数组长度,本例传过来8个十六进制字符，所以二进制共32位，因为1个十六进制字符转为4位的二进制
	char *newArray = (char *)malloc(newLength*sizeof(char));//申请新的内存空间
	newArray[newLength] = '\0';//第32位放个'\0'代表你的字符数组的截止，也就是0-31存的是32个二进制字符

	//下面对每个十六进制转为二进制
	for (i = originalLength - 1; i >= 0; i--)
	{
		int hexToDec=0;//首先将十六进制转为十进制
		if (originArray[i] >= 'a'&&originArray[i] <= 'f')	hexToDec = originArray[i] - 'a' + 10;
		else if (originArray[i] >= 'A'&&originArray[i] <= 'F')	hexToDec = originArray[i] - 'A' + 10;
		else if (originArray[i] >= '0'&&originArray[i] <= '9')	hexToDec = originArray[i] - '0';

		int bitLength = 0;
		//将十进制转为二进制，并保存到新的数组中
		while (bitLength < 4)//一个10进制转为4个二进制位，如7转为0111
		{
			int temp = hexToDec % 2;
			newArray[--newLength] = hexToDec % 2+'0';
			hexToDec = hexToDec / 2;
			bitLength++;
		}
	}
	return newArray;

}
int main(void)
{
	char *array = "7F0AFF1F";
	char *newArray = HexToBinary(array);
	printf("%s\n", newArray);

	system("pause");
}