#include <stdio.h>
#include <stdlib.h>
char* HexToBinary(char * array)
{
	char * originArray = array;

	//��ȡ���������ַ�����ĳ���
	int originalLength = 0;
	while (*array)
	{
		originalLength++;
		array++;
	}

	int i = 0;
	int newLength = originalLength * 4;//�µ����鳤��,����������8��ʮ�������ַ������Զ����ƹ�32λ����Ϊ1��ʮ�������ַ�תΪ4λ�Ķ�����
	char *newArray = (char *)malloc(newLength*sizeof(char));//�����µ��ڴ�ռ�
	newArray[newLength] = '\0';//��32λ�Ÿ�'\0'��������ַ�����Ľ�ֹ��Ҳ����0-31�����32���������ַ�

	//�����ÿ��ʮ������תΪ������
	for (i = originalLength - 1; i >= 0; i--)
	{
		int hexToDec=0;//���Ƚ�ʮ������תΪʮ����
		if (originArray[i] >= 'a'&&originArray[i] <= 'f')	hexToDec = originArray[i] - 'a' + 10;
		else if (originArray[i] >= 'A'&&originArray[i] <= 'F')	hexToDec = originArray[i] - 'A' + 10;
		else if (originArray[i] >= '0'&&originArray[i] <= '9')	hexToDec = originArray[i] - '0';

		int bitLength = 0;
		//��ʮ����תΪ�����ƣ������浽�µ�������
		while (bitLength < 4)//һ��10����תΪ4��������λ����7תΪ0111
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