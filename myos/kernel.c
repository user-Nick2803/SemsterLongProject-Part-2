#define VGA_MEMORY (char*)0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25




void main() {
        
        clear_terminal();
        
	char* const VGA_BUFFER = (char*) 0xb8000;
	char* str = "Hello World";

	for (int i=0; str[i] != '\0'; i++) {
		VGA_BUFFER[i*2] = str[i];
	}
      
        print_string("HELLO");
        print_line("WORLD");
        print_string("TODAY");
        
	return;
}



  


