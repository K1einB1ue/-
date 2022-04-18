#include"./KB_Ex.h"



unsigned char m_strcmp(const char* str1, const char* str2, unsigned int length) {
  while (length--) {
    if (*(str1++)!= *(str2++)) {
      return 0;
    }
  }
  return 1;
}


unsigned char number_to_ascii(unsigned int dat, char *p, unsigned char neg_type, unsigned char radix){ 
    int   neg_dat;
    unsigned int  pos_dat;
    unsigned char   temp_data = 0;
    unsigned char   valid_num = 0;
    
    if(neg_type){
        neg_dat = (int)dat;               //获得32位数据
        if(neg_dat<0) neg_dat = -neg_dat;   //如果数字小于0
        while(1){                           //按进制转化为字符串
            *p = neg_dat%radix + '0';       
            neg_dat = neg_dat/radix;        
            valid_num++;
            
            if(!neg_dat) break;
            p++;
        }
    }else{
        pos_dat = dat;
        while(1){
            temp_data = pos_dat%radix;
            if(10 <= temp_data) temp_data += 'A'-10;
            else                temp_data += '0';
            
            *p = temp_data;
            
            pos_dat = pos_dat/radix;
            valid_num++;
            
            if(!pos_dat) break;
            p++;
        }
    }
    return valid_num;
}