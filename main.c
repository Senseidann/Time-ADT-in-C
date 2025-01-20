#include <stdio.h>
typedef struct {
 int hours;
 int minutes;
 int seconds;
} Time;
void setTime(Time *t, int hours, int minutes, int seconds) {
 if (hours >= 0 && hours < 24) {
 t->hours = hours;
 } else {
 t->hours = 0; 
 }
 if (minutes >= 0 && minutes < 60) {
 t->minutes = minutes;
 } else {
 t->minutes = 0;
 }
 if (seconds >= 0 && seconds < 60) {
 t->seconds = seconds;
 } else {
 t->seconds = 0;
 }
}
void displayTime(const Time *t) {
 printf("%02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}
void advanceTime(Time *t, int sec) {
 
 t->seconds += sec;
 while (t->seconds >= 60) {
 t->seconds -= 60;
 t->minutes += 1;
 }
 while (t->minutes >= 60) {
 t->minutes -= 60;
 t->hours += 1;
 }
 if (t->hours >= 24) {
 t->hours = t->hours%24;
 }
}
int compareTime(const Time *t1, const Time *t2) {
 if (t1->hours < t2->hours) return -1;
 if (t1->hours > t2->hours) return 1;
 if (t1->minutes < t2->minutes) return -1;
 if (t1->minutes > t2->minutes) return 1;
 if (t1->seconds < t2->seconds) return -1;
 if (t1->seconds > t2->seconds) return 1;
 return 0; 
}
int main() {
 Time t1, t2;
 setTime(&t1, 17, 15, 23);
 setTime(&t2, 15, 35, 44);
 printf("Time in first instance: ");
 displayTime(&t1);
 printf("Time in second instance: ");
 displayTime(&t2);
 advanceTime(&t1, 3000);
 printf("Time after extending for 3000 seconds: ");
 displayTime(&t1);
 int comparison = compareTime(&t1, &t2);
 if(comparison == 0) {
 printf("Time 1 is same as Time 2.\n");
 } else if(comparison > 0) {
 printf("Time 1 is more than Time 2.\n");
 } else {
 printf("Time 1 is lesser than Time 2.\n");
 }
 return 0;
}
