# Smart-Tachometer-

Introduction and Background:
A Tachometer (RPM Gauge) is an instrument measuring the rotation speed of a shaft or a disk 
as in a motor or other machine. It usually displays revolutions per minute (RPM) on a calibrated 
analogue dial, but digital displays are increasing common. The word comes from Greek 
(Tachos=Speed, Metrons=Measure). Both Tachometer and speedometer have the ideal 
meaning and are similar that is devices used to measure Speed. 
The First Tachometer was described in a paper to the Royal Society of Arts in 1810. It consisted 
of a Bowl of mercury in such a way that centrifugal force caused level on central tube to fall 
when rotated and brought down the level in a narrower tube above filled with colored spirit. 
Bowl was connected to machinery to be measured by pulleys. Modern tachometers are however 
way too developed and modified in form as well as operation from the old bowl type ones. 
In machinery and rotor operations Handheld Tachometers were more common until the digital 
era. In these meters, a pointer tip was provided which needed to be inserted into the Rotor shaft 
and then measure the speed of the Rotor. This required a huge amount of accuracy and attention 
in order to carefully insert the meter tip in to the shaft. In case if the meter gets displaced or 
position changes by manual errors then severe reading error occur and even the meter gets 
faulty. To avoid these manual errors a better way and method of Laser Tachometers was introduced. 
Its main focus and aim was to avoid contact of meter and reduce manual errors. This idea of 
the meter operation was to switch on laser light incident on the rotor shaft. The light received 
or reflected back from the rotor when received by Meter sensor would then display the rate of 
the light being received in Rotations per minute. These even had the demerits and limitations 
that, manual operation of the meter, even away from the machine can cause an error, if the laser 
to be incident on the shaft gets away or disturbed if the meter is not held steady. 

Aim and Objective:
The main aim of the following project is to avoid the manual issues and problems regarding 
handheld and laser tachometers. The idea of the project developed is to use a transmitter 
receiver set in order to receive and transmit the RPM Data through the digital way. Thus it 
would ensure that readings are made properly even if there is no manual presence in order to 
operate the meters. The data will be received through the transmitter circuit, present near the 
Motor Shaft/Rotor and then transmit it to the receiver circuit within a range of 100m. distance 
in all directions.  
Our basic idea behind this was to use electronic circuitry and reduce the error coefficient for 
obtaining accuracy in meter operations. For this Rx-Tx Modules, Arduino Nano, LCD displays 
are some of the materials been used. 

Workflow:

1. Power Supply Operation
We will provide single phase 230V, 50Hz supply as an input to the SMPS. That SMPS will convert AC into 5V, DC. Then this 5V supply acts as an excitation for the 
Transmitter circuit. DC excitation of 6V is provided to the receiver circuit using 4, AA Batteries of 1.5V which are placed in the battery case arranged in series to get required excitation. 
 
2. Revolution Counter Working 
Next step is to ensure the proper fitting of IR sensor, closer to the rotating shaft which will 
provide pulses as the shaft rotates. Shaft of the machine is modified by sticking a black coloured 
tape which will form a radius of the shaft. Whenever this black tape comes in front of the IR 
sensor, it will give a low pulse output for the time for which the black tap is in front of it, else 
will give high output. Hence, IR sensor will provide active low signals. Each machine will hold 
transmitter circuit and each transmitter circuit will have 1 IR sensor circuit associated with it. 
 
3. Transmitter Working 
These pulses form the IR sensor will be given to the encoder IC of transmitter circuit and 
different passwords are provided for different transmitter circuits. This encoder IC will now 
convert the incoming pulses from IR sensor and password selected in parallel form into serial 
data and will provide this data to the Transmitter module. This Transmitter module will 
superimpose the message signal (Serial converted IR pulses) with its modulating operating 
frequency of 443 MHz and will transmit it via FM Radio signals for a distance more than 40 
meters. 

 
4. Receiver Working 
This transmitted 443MHz frequency will be Tuned by the Receiver module connected in 
Receiver circuit and will separate out message signal from FM signal and will give it to 
Decoder IC. Decoder IC will Read out only that serial input for which password input is 
provided and will convert serial input data into parallel data and will give the low output 
accordingly in the pins.


5. RPM Measurement working 
Arduino Nano will accept an input signal from the decoder IC and process these signals 
according to the program input. Basic function of Arduino is to take the pulses compare it with 
time and display the number of revolutions per minute in the TM167 4-digit 7 segment display. 
For which machine user wants to read the revolutions will be selected via buttons on the 
Tachometer. Arduino according to the selected machine from the user will change the password 
of the receiver IC such that particular data is only received by the receiver circuit. And reading 
of that particular machine is displayed on the TM167 and selected machine information is 
displayed on the 16X2 LCD.


Advantages: 
• Contact- Free measurement. 
• No chances for any manual error while measuring. 
• Reduced errors. 
• More effective and efficient Measurement. 
• Result Data can be tracked and collected even from a distance.  
 
  
Future Scope: 
• The project can be employed at industries and factories, vehicles where there is a need 
for accuracy. 
• It can be utilized in Machine Laboratories. 
• Data can be collected even through a cell-phone.  
• At large rating machines for human safety purpose. 
