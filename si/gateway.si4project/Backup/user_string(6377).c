
#include "stdint.h"
#include "user_string.h"

/***************************************************************************************************
 * @fn      Srting_to_Hex
 *
 * @brief   ���ַ���ת��Ϊ16��������֧�ִ�Сд�ַ���
 *			"0011AB"-->0x00,0x11,0xAB �����ַ�ת����һ���ֽ�16��������
 *
 * @param   dest�����16��������ָ�룬src���ַ���ָ�룬length �ַ�������/2
 *			
 * @return  NULL
***************************************************************************************************/
void Srting_to_Hex(uint8 *dest, uint8 *src, uint8 length)
{
  uint8 i = 0;
  uint8 ch;
  for(i = 0; i<length; i++)
  {
    ch = src[2*i];
    dest[i] = ch - ((ch <= '9') ? '0':'7');
    
    ch = src[2*i+1];
    dest[i] = ((ch - ((ch <='9') ? '0':'7'))&0x0f) |(dest[i]<<4);
  }
}


/***************************************************************************************************
 * @fn      Hex_To_String
 *
 * @brief   ��16��������ת��Ϊ�ַ���  Сд�ַ���
 *			0x00,0x11,0xAB-->"0011ab"
 *
 * @param   dest ����ַ���ָ�룬src 16������ָ�룬 16�������ֽ���
 *			
 * @return  NULL
***************************************************************************************************/
void Hex_To_SmallString(uint8_t *dest, uint8_t *src, uint8_t length)
{
  uint8_t *xad;
  uint8_t i = 0;
  uint8_t ch;
  xad = src;
  for(i = 0; i<length; i++,xad++)
  {
    ch = (*xad >> 4) & 0x0f;
    dest[i<<1] = ch + ((ch < 10) ? '0':'W');
    
    ch = *xad & 0x0f;
    dest[(i<<1) + 1] = ch + ((ch < 10) ? '0':'W');
  }
}

uint32 strtou32(char *str)
{
	uint32 i=0,tmp=0;
	while(str[i]!='\0')
	{
		if(str[i]>='0'&&str[i]<='9')
		tmp=tmp*10+(str[i]-'0');
		i++;
	}
	return tmp;
}

//ȥ���ո��tab���ɼ��ַ�
char *strim(char *str)  // 
{
	char * tail = str;
	char * next = str;

	while(*next)
	{
    if(*next >32)
		{
			if(tail < next)
				*tail = *next;
			tail++;
		}
		next++;
	}
	*tail = '\0';

	return str;
}
