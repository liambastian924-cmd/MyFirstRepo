// See https://aka.ms/new-console-template for more information
using static System.Convert;
using static SplashKitSDK.SplashKit;
const int MINUTES_PER_HOUR = 60;
string name;
string userInput;
double distance, time;
double speed;
double remainingDistance, timetoDestination;
double totalDistance, totalTime;
Write("What is your name: ");
name = ReadLine();

WriteLine();
WriteLine($"Hi {name}.");
WriteLine();

Write("How far have you travelled so far? Enter km: ");
userInput = ReadLine();
distance = Convert.ToDouble(userInput);

Write("How long has it taken? Enter minutes: ");
userInput = ReadLine();
time = Convert.ToDouble(userInput);

speed = distance / (time / MINUTES_PER_HOUR);

WriteLine();
WriteLine($"Your average speed is {speed} km/h");
WriteLine();

Write("How far do you have to go? Enter km: ");
userInput = ReadLine();
remainingDistance = Convert.ToDouble(userInput);

timetoDestination = remainingDistance / speed * MINUTES_PER_HOUR;

WriteLine($"You will take another {timetoDestination} minutes before you arrive.");

totalDistance = distance + remainingDistance;
totalTime = time + timetoDestination;

WriteLine($"Total distance will be {totalDistance} km.");
WriteLine($"Total time will be {totalTime} minutes.");