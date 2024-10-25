#include "console.h"

#define VGA_MEMORY (char*)0xB8000
static int terminal_position = 0;

void clear_terminal(){

char* vga = VGA_MEMORY;
  
  for(int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i += 2){
  vga[i] = '\0'; //null character for blank space
  vga[i + 1] = 0x07;
  }
  
}

void print_character(char c){

    char* vga = VGA_MEMORY;

    vga[terminal_position] = c;
    vga[terminal_position + 1] = 0x07;

    terminal_position += 2;
}

void print_string(char* str){

  while(*str){
    print_character(*str);
    str++;
  }
}

void print_line(char*str){
  print_string(str);
  
    int row_offset = VGA_WIDTH * VGA_BYTES_PER_CHARACTER;
    terminal_position = (terminal_position / row_offset + 1) * row_offset;


}
