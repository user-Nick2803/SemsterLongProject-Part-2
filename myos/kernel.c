#define VGA_MEMORY (char*)0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25


void clear_terminal(){

char* vga = VGA_MEMORY;
  
  for(int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i += 2){
  vga[i] = '\0'; //null character for blank space
  vga[i + 1] = 0x07;
  }
  
}

void main() {
        
        clear_terminal();
        
	char* const VGA_BUFFER = (char*) 0xb8000;
	char* str = "Hello World";

	for (int i=0; str[i] != '\0'; i++) {
		VGA_BUFFER[i*2] = str[i];
	}
        
        clear_terminal();
        print_string("HELLO");
        print_line("WORLD");
        print_string("TODAY");
        
	return;
}



  


