### SOURCE
A much more detailed explanation
https://www.youtube.com/watch?v=qGbuzuVSzVs&t=181s

### TURNING ARDUINO INTO PROGRAMER
- Go to Exampls -> ArduinoISP - ArduinoISP
- Choose board (Arduino Uno)
- Choose Port
- Upload sketch
- Your arduino is now a programmer

### ADDING THE MINICORE BOARDS TO YOUR ARDUINO IDE
- Go to File -> Preferences
- Open "Additional board manager URLs"
- Add this line "https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json"
- Exit Preferences
- Go to BoardManager tab on the left
- Search for "MiniCore"
- Install it

### CONNECTING ATMEGA328 TO PROGRAMMER
- Construct the below circuit (I know its weird that they connect 5V and GND to eachother a lot but it seems to be important)
![[Pasted image 20250604180929.png]]

### UPLOADING CODE TO ATMEGA328 FROM YOUR NEW PROGRAMMER
- Open the sketch you would like to upload to the Atmega328
- Tools -> Board -> Minicore -> Select "Atmega328"
- Tools -> Port -> Select "Atmega328"Select the port your arduino programmer is connected to
- Tools -> Port -> Clock -> Select "Internal 8MHz" (I don't need an external clock)
- Tools -> Version -> Select "328 / 328A" (this is the one I have)
- Tools -> Programmer ->Select "Arduino as ISP"
- Tools -> Click "Burn Bootloader"
- Now we are ready to upload
- Go to Sketch -> Click "Upload Using Programmer"
- Your program should be on the Atmega328 now (woohoo !)
### ATMEGA PINOUT
The pinout for reference (this is stupidly hard to find for some reason)
![[Pasted image 20250807190426.png]]
![[Pasted image 20250807181730.png]]