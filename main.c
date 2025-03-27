/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 void initialize_system(int rooms, int light[], int temp[], int motion[], int lock[], int *motion_count) {
     for (int i = 0; i < rooms; i++) {
         light[i] = 0; // Lights OFF
         temp[i] = 22; // Default temperature (22°C)
         motion[i] = 0; // No motion detected
         lock[i] = 1; // Doors locked
     }
     *motion_count = 0; // No motion detected initially
     printf("System Initialized.\n");
 }
 
 void toggle_light(int rooms, int light[]) {
     int room;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &room);
     room--; // Convert to 0-based index
 
     if (room >= 0 && room < rooms) {
         light[room] = 1 - light[room]; // Toggle light state
         printf("Light in Room %d is now %s.\n", room + 1, light[room] ? "ON" : "OFF");
     } else {
         printf("Invalid room number.\n");
     }
 }
 
 void read_temperature(int rooms, int temp[]) {
     int room;
     printf("Enter room number to read temperature (1-%d): ", rooms);
     scanf("%d", &room);
     room--; // Convert to 0-based index
 
     if (room >= 0 && room < rooms) {
         printf("Temperature in Room %d is %d°C.\n", room + 1, temp[room]);
     } else {
         printf("Invalid room number.\n");
     }
 }
 
 void check_motion(int rooms, int motion[]) {
     int room;
     printf("Enter room number to check motion sensor (1-%d): ", rooms);
     scanf("%d", &room);
     room--; // Convert to 0-based index
 
     if (room >= 0 && room < rooms) {
         printf("Motion in Room %d: %s\n", room + 1, motion[room] ? "Detected" : "No Motion");
     } else {
         printf("Invalid room number.\n");
     }
 }
 
 void lock_unlock_security(int rooms, int lock[]) {
     int room;
     printf("Enter room number to lock/unlock (1-%d): ", rooms);
     scanf("%d", &room);
     room--; // Convert to 0-based index
 
     if (room >= 0 && room < rooms) {
         lock[room] = 1 - lock[room]; // Toggle lock state
         printf("Room %d is now %s.\n", room + 1, lock[room] ? "Locked" : "Unlocked");
     } else {
         printf("Invalid room number.\n");
     }
 }
 
 void house_status(int rooms, int light[], int temp[], int motion[], int lock[]) {
     printf("House Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1, 
             light[i] ? "ON" : "OFF", temp[i], 
             motion[i] ? "Motion Detected" : "No Motion", 
             lock[i] ? "Locked" : "Unlocked");
     }
 }
 
 void auto_lock_security(int rooms, int motion[], int lock[], int *motion_count) {
     if (*motion_count >= 5) {
         for (int i = 0; i < rooms; i++) {
             if (motion[i] == 0) {
                 lock[i] = 1; // Lock door if no motion detected
             }
         }
         printf("Auto-locking enabled for rooms with no motion.\n");
         *motion_count = 0; // Reset motion count after locking
     }
 }
 
 void temperature_alert(int rooms, int temp[]) {
     for (int i = 0; i < rooms; i++) {
         if (temp[i] > 30) {
             printf("Warning: Room %d has exceeded 30°C! Temperature: %d°C\n", i + 1, temp[i]);
         }
     }
 }
 
 void energy_saving_mode(int rooms, int light[]) {
     int all_lights_on = 1;
     for (int i = 0; i < rooms; i++) {
         if (light[i] == 0) {
             all_lights_on = 0;
             break;
         }
     }
 
     if (all_lights_on) {
         printf("Energy Saving Mode: All lights are ON. Consider turning them off.\n");
     }
 }
 
 int main() {
     int rooms, choice;
     int *light, *temp, *motion, *lock;
     int motion_count = 0;
 
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
 
     // Dynamically allocate memory for arrays based on number of rooms
     light = (int *)malloc(rooms * sizeof(int));
     temp = (int *)malloc(rooms * sizeof(int));
     motion = (int *)malloc(rooms * sizeof(int));
     lock = (int *)malloc(rooms * sizeof(int));
 
     if (light == NULL || temp == NULL || motion == NULL || lock == NULL) {
         printf("Memory allocation failed. Exiting.\n");
         return -1;
     }
 
     // Initialize system
     initialize_system(rooms, light, temp, motion, lock, &motion_count);
 
     do {
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n");
         printf("2. Read Temperature\n");
         printf("3. Check Motion Sensor\n");
         printf("4. Lock/Unlock Security System\n");
         printf("5. House Status Summary\n");
         printf("6. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1:
                 toggle_light(rooms, light);
                 break;
             case 2:
                 read_temperature(rooms, temp);
                 break;
             case 3:
                 check_motion(rooms, motion);
                 motion_count++; // Increment motion count for auto-lock check
                 auto_lock_security(rooms, motion, lock, &motion_count);
                 break;
             case 4:
                 lock_unlock_security(rooms, lock);
                 break;
             case 5:
                 house_status(rooms, light, temp, motion, lock);
                 temperature_alert(rooms, temp);
                 energy_saving_mode(rooms, light);
                 break;
             case 6:
                 printf("Exiting...\n");
                 break;
             default:
                 printf("Invalid choice. Please try again.\n");
         }
     } while (choice != 6);
 
     // Free dynamically allocated memory
     free(light);
     free(temp);
     free(motion);
     free(lock);
 
     return 0;
 }
 