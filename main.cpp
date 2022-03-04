#include "clui.h"
#include <bits/stdc++.h>
#include <iostream>
#include<time.h>
#include <fstream>
#include <vector>
#include <windows.h>
#include <cstring>

using namespace std;
clock_t start, ending;
bool ejra = true;//to run the game when the player is still in the game

void Menu() {
    //to show the player a list of options
    change_color(COLOR_ORANGE_3);
    printf("\nWelcome to TYPIST!");
    change_color_rgb(235, 238, 252);
    printf("\n\nSelect an option below : ");
    printf("\n 1. Let's Start the game!");
    printf("\n 2. My stats ");
    printf("\n 3. Exit \n");
    change_color(COLOR_DEFAULT);
}

void help() {
    //in the beginning of each level this will guide the player
    printf("\n");
    change_color(COLOR_RED);
    printf("\n(Help : BE CAREFUL! The game is sensitive to capital and small letters.)\n");
    change_color_rgb(190, 235, 232);
    printf("\n(Help : press ENTER when you finished typing the text.)\n");
    printf("\n(Help : type G to play the game.\n");
    printf("\n(Help : type Q if you want to quit.\n\n");
    change_color(COLOR_DEFAULT);

}

void levels(int i, string level) {
    //  begin each level + text of each level
    if (i == 1) {
        printf("\n Alright Lets began level one! type the text below.\n");
        cout << endl << endl << " Text : " << level << endl;
    }
    if (i == 2) {
        printf("\n Alright Lets began level two! type the text below.\n");
        cout << endl << endl << " Text : " << level << endl;
    }
    if (i == 3) {
        printf("\n Alright Lets began level three! type the text below.\n");
        cout << endl << endl << " Text : " << level << endl;
    }
}

int countcommenchars(string a, string b) {
    // to count the number of correct characters the played has interred
    int n1 = a.length(), n2 = b.length();
    int i = 0, correct = 0;
    for (i; i < min(n1, n2); i++) {
        if (a[i] == b[i]) {
            correct++;
            char c[correct];
            c[i] = a[i];
        }
    }
    return correct;
}

int countuncommenchars(string a, string b) {
    // to count the number of wrong characters the played has interred
    int n1 = a.length(), n2 = b.length();
    int i = 0, wrong = 0;
    for (i; i < min(n1, n2); i++) {
        if (a[i] != b[i]) {
            wrong++;
        }
    }
    return wrong;
}

void removeSpaces(char *str) {
    // to remove the space between characters 
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}

void findcommenchars(string str1, int n1, string str2, int n2) {
    // to find the characters that match with levels's text
    int mini = min(n1, n2), i = 0;
    int uncommens = mini - countuncommenchars(str1, str2);
    int commens = mini - countcommenchars(str1, str2);
    char a[256];
    char b[256];
    if (uncommens == 0) {
        printf("\nThere was no common characters :/\n");
    } else if (commens != 0) {
        for (i; i < 256; i++) {
            if (str1[i] == str2[i]) {
                a[i] = str1[i];
                b[i] = ' ';
            } else if (str1[i] != str2[i]) {
                b[i] = str1[i];
                a[i] = ' ';
            }
        }
        removeSpaces(a);
        if (a[i] == 0) {
            cout << endl << "Your correct characters are : 0" << endl;
        } else
            cout << endl << "Your correct characters are : " << a << endl;
    } else {
        printf("\nThere was no uncommon characters XD\n");
        // to provide a good sound to give player energy
        Beep(1568, 200);
        Beep(1568, 200);
        Beep(1568, 200);
        Beep(1245, 1000);
        Beep(1397, 200);
        Beep(1397, 200);
        Beep(1397, 200);
        Beep(1175, 1000);
    }
}

void finduncommenchars(string str1, int n1, string str2, int n2) {
    // to find the characters that doesn't match with levels's text
    int mini = min(n1, n2), i = 0;
    int commens = mini - countcommenchars(str1, str2);
    int uncommens = mini - countuncommenchars(str1, str2);
    char a[n1];
    char b[n1];
    if (commens == 0) {
        printf("\nThere was no uncommon characters XD\n");
    } else if (uncommens != 0) {
        for (i; i < n1; i++) {
            if (str1[i] == str2[i]) {
                a[i] = str1[i];
                b[i] = ' ';
            } else if (str1[i] != str2[i]) {
                b[i] = str2[i];
                a[i] = ' ';
            }
        }
        removeSpaces(b);
        cout << endl << "Your wrong characters are : " << b << endl;
    } else {
        printf("\nThere was no common characters :/\n");
        // to provide a sad sound to show the player we are disappointed
        Beep(150, 2000);
        Beep(160, 2000);
        Beep(170, 2000);
        Beep(120, 1350);
    }
}

void uncomenlevel1(string str1, int n1, string str2, int n2) {
    /* there was a bug with the length of this level so i had to separate 
    finding the characters that doesn't match from other levels */
    int mini = min(n1, n2), i = 0;
    int commens = mini - countcommenchars(str1, str2);
    int uncommens = mini - countuncommenchars(str1, str2);
    char a[40];
    char b[40];
    if (commens == 0) {
        printf("\nThere was no uncommon characters XD\n");
    } else if (uncommens != 0) {
        for (i; i < 40; i++) {
            if (str1[i] != str2[i]) {
                b[i] = str2[i];
                a[i] = ' ';
            }
        }
        removeSpaces(b);
        cout << endl << "Your wrong characters are : " << b << endl;
    } else {
        printf("\nThere was no common characters :/\n");
        Beep(150, 2000);
        Beep(160, 2000);
        Beep(170, 2000);
        Beep(120, 1350);
    }
}

//what should have been typed instead of wrong characters
void shouldhavetyped1(string str1, int n1, string str2, int n2) {
    int mini = min(n1, n2), i = 0;
    int commens = mini - countcommenchars(str1, str2);
    int uncommens = mini - countuncommenchars(str1, str2);
    char a[40];
    char b[40];
    if (commens == 0) {
        printf("\nThere was no uncommon characters XD\n");
    } else if (uncommens != 0) {
        for (i; i < 40; i++) {
            if (str1[i] != str2[i]) {
                b[i] = str2[i];
                a[i] = ' ';
            } else {
                b[i] = ' ';
            }
        }
        //removeSpaces(b);
        cout << endl << "You shoul've written : " << b << endl;
    }
}

void shouldhavetyped2(string str1, int n1, string str2, int n2) {
    int mini = min(n1, n2), i = 0;
    int commens = mini - countcommenchars(str1, str2);
    int uncommens = mini - countuncommenchars(str1, str2);
    int n3 = str2.length();
    char a[n2];
    char b[n2];
    if (commens == 0) {
        printf("\nThere was no uncommon characters XD\n");
    } else if (uncommens != 0) {
        for (i; i < n2; i++) {
            if (str1[i] != str2[i]) {
                b[i] = str2[i];
                a[i] = ' ';
            } else {
                b[i] = ' ';
            }
        }
        //removeSpaces(b);
        cout << endl << "You shoul've written : " << b << endl;
    }
}

void shouldhavetyped3(string str1, int n1, string str2, int n2) {
    int mini = min(n1, n2), i = 0;
    int commens = mini - countcommenchars(str1, str2);
    int uncommens = mini - countuncommenchars(str1, str2);
    int n3 = str2.length() - 4;
    char a[148];
    char b[148];
    if (commens == 0) {
        printf("\nThere was no uncommon characters XD\n");
    } else if (uncommens != 0) {
        for (i; i < 148; i++) {
            if (str1[i] != str2[i]) {
                b[i] = str2[i];
                a[i] = ' ';
            } else {
                b[i] = ' ';
            }
        }
        //removeSpaces(b);
        cout << endl << "You shoul've written : " << b;
    }
}

int accuracy(int right, int len) {
    int a = right * 100;
    return a / len;
}

int stars(int levelnum, string level, string a) {
    // to give the player stars based on the number of correct characters he/she has interred
    int commen = countcommenchars(level, a);
    if (levelnum == 1) {
        if (commen < 4) {
            cout << endl << "Stars : 0" << endl;
        } else if (commen > 4 && commen < 10) {
            cout << endl << "Stars : *" << endl;
        } else if (commen > 10 && commen < 17) {
            cout << endl << "Stars : **" << endl;
        } else if (commen > 17 && commen < 26) {
            cout << endl << "Stars : ***" << endl;
        } else if (commen > 26 && commen < 33) {
            cout << endl << "Stars : ****" << endl;
        } else if (commen == 40) {
            cout << endl << "Stars : *****" << endl;
        }
    } else if (levelnum == 2) {
        if (commen < 5) {
            cout << endl << "Stars : 0" << endl;
        } else if (commen > 5 && commen < 15) {
            cout << endl << "Stars : *" << endl;
        } else if (commen > 15 && commen < 27) {
            cout << endl << "Stars : **" << endl;
        } else if (commen > 27 && commen < 36) {
            cout << endl << "Stars : ***" << endl;
        } else if (commen > 36 && commen < 47) {
            cout << endl << "Stars : ****" << endl;
        } else if (commen == 55) {
            cout << endl << "Stars : *****" << endl;
        }
    } else if (levelnum == 3) {
        if (commen < 10) {
            cout << endl << "Stars : 0" << endl;
        } else if (commen > 10 && commen < 30) {
            cout << endl << "Stars : *" << endl;
        } else if (commen > 30 && commen < 55) {
            cout << endl << "Stars : **" << endl;
        } else if (commen > 55 && commen < 80) {
            cout << endl << "Stars : ***" << endl;
        } else if (commen > 80 && commen < 128) {
            cout << endl << "Stars : ****" << endl;
        } else if (commen == 148) {
            cout << endl << "Stars : *****" << endl;
        }
    }
}

void aftergamelevel1(int seconds, string a, string level)//when the level is finished this will show the level's stats
{
    printf("\nCongratulations! You have finished level 1 in %d seconds! \n", seconds);
    int n1 = level.length(), n2 = a.length();
    int correct1 = countcommenchars(level, a);
    change_color(COLOR_BOLD_YELLOW);
    stars(1, level, a);
    change_color(COLOR_DEFAULT);
    printf("\nHow many Correct characters ? %d\n", correct1);
    change_color(COLOR_GREEN);
    findcommenchars(level, n1, a, n2);
    change_color(COLOR_DEFAULT);
    int wrong1 = countuncommenchars(level, a);
    printf("\nHow many Wrong characters ? %d\n", wrong1);
    change_color_rgb(245, 5, 5);
    uncomenlevel1(level, n1, a, n2);
    // finduncommenchars(one, n1, a, n2);
    change_color(COLOR_BLUE);
    shouldhavetyped1(a, n2, level, n1);
    change_color(COLOR_DEFAULT);
    printf("\nAccuracy : %d%%\n", accuracy(correct1, n1));
    int speed1 = n2 / seconds;
    printf("\nSpeed : %d char/sec \n", speed1);


}

void saveinfilelevel1(string a, string level) {
    // to save some of the informations of level one in file
    int correct1 = countcommenchars(level, a);
    int wrong1 = countuncommenchars(level, a);
    ofstream MyFile1("levelone.txt");
    MyFile1 << endl << "What you typed in level one is :" << endl << endl << a << endl << endl
            << "You typed "
            << correct1 << " correct characters and " << wrong1 << " wrong characters.";
    MyFile1.close();

}

void aftergamelevel2(int seconds, string b, string level) //when the level is finished this will show the level's stats
{
    printf("\nCongratulations! You have finished level 2 in %d seconds! \n", seconds);
    int n12 = level.length(), n22 = b.length();
    int correct2 = countcommenchars(level, b);
    change_color(COLOR_BOLD_YELLOW);
    stars(2, level, b);
    change_color(COLOR_DEFAULT);
    printf("\nHow many Correct characters ? %d\n", correct2);
    change_color(COLOR_GREEN);
    findcommenchars(level, n12, b, n22);
    change_color(COLOR_DEFAULT);
    int wrong2 = countuncommenchars(level, b);
    printf("\n How many Wrong characters ?  %d\n", wrong2);
    change_color_rgb(245, 5, 5);
    finduncommenchars(level, n12, b, n22);
    change_color(COLOR_BLUE);
    shouldhavetyped2(b, n22, level, n12);
    change_color(COLOR_DEFAULT);
    printf("\nAccuracy : %d%%\n", accuracy(correct2, n12));
    int speed2 = n22 / seconds;
    printf("\nSpeed : %d char/sec \n", speed2);
    printf("\nPress any word or number to continue...\n");

}

void saveinfilelevel2(string b, string level) {
    // to save some of the informations of level two in file
    int correct2 = countcommenchars(level, b);
    int wrong2 = countuncommenchars(level, b);
    ofstream MyFile2("leveltwo.txt");
    MyFile2 << endl << "What you typed in level two is :" << endl << endl << b << endl << endl << "You typed "
            << correct2 << " correct characters and " << wrong2 << " wrong characters.";
    MyFile2.close();
}

void aftergamelevel3(int seconds, string c, string level) //when the level is finished this will show the level's stats
{
    printf("\nCongratulations! You have finished level 3 in %d seconds! \n", seconds);
    int n13 = level.length(), n23 = c.length();
    int correct3 = countcommenchars(level, c);
    change_color(COLOR_BOLD_YELLOW);
    stars(3, level, c);
    change_color(COLOR_DEFAULT);
    printf("\nHow many Correct characters ? %d\n", correct3);
    change_color(COLOR_GREEN);
    findcommenchars(level, n13, c, n23);
    change_color(COLOR_DEFAULT);
    int wrong3 = countuncommenchars(level, c);
    printf("\nHow many Wrong characters ? %d\n", wrong3);
    change_color_rgb(245, 5, 5);
    finduncommenchars(level, n13, c, n23);
    change_color(COLOR_BLUE);
    shouldhavetyped3(c, n23, level, n13);
    change_color(COLOR_DEFAULT);
    printf("\nAccuracy : %d%%\n", accuracy(correct3, n13));
    int speed3 = n23 / seconds;
    printf("\nSpeed : %d char/sec \n", speed3);
    printf("\nPress any word or number to continue...\n");

}

void saveinfilelevel3(string c, string level) {
    // to save some of the informations of level three in file
    int correct3 = countcommenchars(level, c);
    int wrong3 = countuncommenchars(level, c);
    ofstream MyFile3("levelthree.txt");
    MyFile3 << endl << "What you typed in level three is :" << endl << endl << c << endl << endl << "You typed "
            << correct3 << " correct characters and " << wrong3 << " wrong characters.";
    MyFile3.close();
}

void Press() {
    printf(" press 1 if you want to continue.\n ");
    printf("press 2 if you want to see your stats.\n ");
    printf("press 3 if you want to quit.\n ");
    printf("press ENTER after you chose.\n\n");
}

void letsquit(int k) {
    //check if the player wants to leave a level or not
    if (k == 1) {
        printf("\n Are you sure you want to leave level 1 ?\n");
        printf(" Y : yes i want to leave.\n");
        printf(" S : I want to see my stats.\n");
        printf(" N : no i will continue\n");
    }
    if (k == 2) {
        printf("\n Are you sure you want to leave level 2 ?\n");
        printf(" Y : yes i want to leave.\n");
        printf(" S : I want to see my stats.\n");
        printf(" N : no i will continue\n");
    }
    if (k == 3) {
        printf("\n Are you sure you want to leave level 3 ?\n");
        printf(" Y : yes i want to leave.\n");
        printf(" S : I want to see my stats.\n");
        printf(" N : no i will continue\n");

    }
}

void stayorleave() {
    printf("Are you sure you want to leave ?\n");
    printf("Y : Yes I'm sure\n");
    printf("N : No I'll stay\n");
}

void stats(int corrects, int wrongs, int accuracies) {
    change_color_rgb(235, 174, 233);
    printf("\n Your stats is : \n\n");
    printf("Total correct characters : %d\n", corrects);
    printf("Total wrong characters : %d\n", wrongs);
    printf("Total accuracy : %d%%\n\n\n", accuracies);
    change_color(COLOR_DEFAULT);

}

void timer(int sec) {
    Sleep(sec * 1000);
    // to provide delay
}

int main() {
    init_clui(); // initialize the library
    Menu();
    string level = "1";
    string a;
    string b;
    string c;
    // read each level's text from file
    string onetext, levelone, twotext, leveltwo, threetext, levelthree;
    ifstream levelonetext("one.txt");
    while (getline(levelonetext, onetext)) {
        levelone = onetext;
    }
    ifstream leveltwotext("two.txt");
    while (getline(leveltwotext, twotext)) {
        leveltwo = twotext;
    }
    ifstream levelthreetext("three.txt");
    while (getline(levelthreetext, threetext)) {
        levelthree = threetext;
    }

    int select, edame, afterstats, aftergaming, afterquit;
    char quiting1, quiting2, quiting3;
    cin >> select;
    while (ejra == true) {

        if (aftergaming == 1 || edame == 1 || afterstats == 1) {
            clear_screen();
            Menu();
            cin >> select;
            clear_screen();
        }
        if (select == 1) {
            // read level's num from file
            ifstream MyReadFile("level.txt");
            string mytext;
            while (getline(MyReadFile, mytext)) {
                level = mytext;
            }

            while (level == "1") {
                //level1
                clear_screen();
                change_color(COLOR_ORANGE_1);
                printf("Welcome to LEVEL 1");
                change_color(COLOR_DEFAULT);
                help();
                char quit1;
                cin >> quit1;

                if (quit1 == 'G' || quiting1 == 'N' || afterquit == 1) {
                    clear_screen();
                    levels(1, levelone);
                    //string a;

                    start = clock();
                    cin.ignore();
                    getline(cin, a);
                    ending = clock();
                    int seconds1 = ((int) (ending - start)) / CLOCKS_PER_SEC;
                    clear_screen();
		    //save stats in file
                    aftergamelevel1(seconds1, a, levelone);
                    ofstream statcorrect1("statcorrect.txt");
                    statcorrect1 << countcommenchars(levelone, a);
                    statcorrect1.close();
                    ofstream statwrong1("statwrong.txt");
                    statwrong1 << countuncommenchars(levelone, a);
                    statwrong1.close();
                    ofstream stataccuracy1("stataccuracy.txt");
                    int n1 = levelone.length();
                    stataccuracy1 << accuracy(countcommenchars(levelone, a), n1);
                    stataccuracy1.close();
                    saveinfilelevel1(a, levelone);
		   //limit the player! he/she cant go to the next level untill she/he has finished this level
                    if (countcommenchars(levelone, a) != 40) {
                        change_color(COLOR_ORANGE_1);
                        cout << endl << endl
                             << " Sorry! you can't go to the next level until you get 5 stars in this level.";
                        cout << endl << endl << " Wait a little and then Try again ^__' ";
                        change_color(COLOR_DEFAULT);
                        timer(12);
                        level = "1";
                    } else {
                        printf("\nPress any word or number to continue...\n");
                        char continuing1;
                        cin >> continuing1;
                        clear_screen();
                        level = "2";
			//update level num in file
                        ofstream MyFile("level.txt");
                        MyFile << level;
                        MyFile.close();
                        ifstream MyReadFile("level.txt");
                        string mytext = "2";

                    }
                }
                if (quit1 == 'Q') {
                    clear_screen();
                    letsquit(1);
                    cin >> quiting1;
                    clear_screen();
                    if (quiting1 == 'Y') {
                        quit();
                    }
                    if (quiting1 == 'S') {
                        int n1 = levelone.length();
                        stats(countcommenchars(levelone, a), countuncommenchars(levelone, a),
                              accuracy(countcommenchars(levelone, a), n1));
                        Press();
                        cin >> afterquit;
                    }
                }
                clear_screen();
            }
	    // read the level from file
            while (getline(MyReadFile, mytext)) {
                level = mytext;
            }

            //level2
            while (level == "2") {

                clear_screen();
                change_color(COLOR_ORANGE_1);
                printf("Welcome to LEVEL 2");
                change_color(COLOR_DEFAULT);
                help();
                char quit2;
                cin >> quit2;
                clear_screen();
                if (quit2 == 'Q') {
                    letsquit(2);
                    cin >> quiting2;
                    clear_screen();
                    if (quiting2 == 'Y') {
                        quit();
                    }
                    if (quiting2 == 'S') {
		        // read stats from file
                        string statcorrecttwo, statwrongtwo, statacctwo;
                        ifstream statcorrect2("statcorrect.txt");
                        string mytext1;
                        while (getline(statcorrect2, mytext1)) {
                            statcorrecttwo = mytext1;
                        }
                        ifstream statwrong2("statwrong.txt");
                        string mytext2;
                        while (getline(statwrong2, mytext2)) {
                            statwrongtwo = mytext2;
                        }
                        ifstream statacc2("stataccuracy.txt");
                        string mytext3;
                        while (getline(statacc2, mytext3)) {
                            statacctwo = mytext3;
                        }
                        stats(stoi(statcorrecttwo), stoi(statwrongtwo), stoi(statacctwo));
                        Press();
                        cin >> afterquit;
                    }
                }
                if (quit2 == 'G' || quiting2 == 'N') {
                    clear_screen();
                    levels(2, leveltwo);
                    //string b;
                    start = clock();
                    cin.ignore();
                    getline(cin, b);
                    ending = clock();
                    int seconds2 = ((int) (ending - start)) / CLOCKS_PER_SEC;
                    clear_screen();
		    // update stats in file
                    ofstream statcorrect1("statcorrect.txt");
                    statcorrect1 << countcommenchars(levelone, a) + countcommenchars(leveltwo, b);
                    statcorrect1.close();
                    ofstream statwrong1("statwrong.txt");
                    statwrong1 << countuncommenchars(levelone, a) + countuncommenchars(leveltwo, b);
                    statwrong1.close();
                    ofstream stataccuracy1("stataccuracy.txt");
                    int n2 = levelone.length() + leveltwo.length();
                    stataccuracy1 << accuracy(countcommenchars(levelone, a) + countcommenchars(leveltwo, b), n2);
                    stataccuracy1.close();
                    aftergamelevel2(seconds2, b, leveltwo);
                    saveinfilelevel2(b, leveltwo);
                    if (countcommenchars(leveltwo, b) != 55) {
		    //limit the player! he/she cant go to the next level untill she/he has finished this level
                        change_color(COLOR_ORANGE_1);
                        cout << endl << endl
                             << " Sorry! you can't go to the next level until you get 5 stars in this level.";
                        cout << endl << endl << " Wait a little and then Try again ^__' ";
                        change_color(COLOR_DEFAULT);
                        timer(12);
                        level = "2";
                    } else {
                        char continuing2;
                        cin >> continuing2;
                        level = "3";
			//update level num in file
                        ofstream MyFile("level.txt");
                        MyFile << level;
                        MyFile.close();
                        ifstream MyReadFile("level.txt");
                        string mytext = "2";
                    }
                }

                clear_screen();
            }
	    // read level num from file
            while (getline(MyReadFile, mytext)) {
                level = mytext;
            }
            // level3
            while (level == "3") {
                clear_screen();
                change_color(COLOR_ORANGE_1);
                printf("Welcome to LEVEL 3");
                change_color(COLOR_DEFAULT);
                help();
                char quit3;
                cin >> quit3;
                if (quit3 == 'Q') {
                    clear_screen();
                    letsquit(3);
                    cin >> quiting3;
                    clear_screen();
                    if (quiting3 == 'Y') {
                        quit();
                    }
                    if (quiting3 == 'S') {
			// read stats from file
                        string statcorrectthree, statwrongthree, stataccthree;
                        ifstream statcorrect3("statcorrect.txt");
                        string mytext1;
                        while (getline(statcorrect3, mytext1)) {
                            statcorrectthree = mytext1;
                        }
                        ifstream statwrong3("statwrong.txt");
                        string mytext2;
                        while (getline(statwrong3, mytext2)) {
                            statwrongthree = mytext2;
                        }
                        ifstream statacc3("stataccuracy.txt");
                        string mytext3;
                        while (getline(statacc3, mytext3)) {
                            stataccthree = mytext3;
                        }
                        stats(stoi(statcorrectthree), stoi(statwrongthree), stoi(stataccthree));
                        Press();
                        cin >> afterquit;
                    }
                }
                clear_screen();
                if (quit3 == 'G' || quiting3 == 'N') {
                    levels(3, levelthree);
                    //  string c;
                    start = clock();
                    cin.ignore();
                    getline(cin, c);
                    ending = clock();
                    int seconds3 = ((int) (ending - start)) / CLOCKS_PER_SEC;
                    clear_screen();
                    int sum1 = countcommenchars(levelone, a) + countcommenchars(leveltwo, b) +
                               countcommenchars(levelthree, c);
                    int sum2 = countuncommenchars(levelone, a) + countuncommenchars(leveltwo, b) +
                               countuncommenchars(levelthree, c);
                    int n3 = levelone.length() + leveltwo.length() + levelthree.length();
                    ofstream statcorrect1("statcorrect.txt");
                    statcorrect1 << sum1;
                    statcorrect1.close();
                    ofstream statwrong1("statwrong.txt");
                    statwrong1 << sum2;
                    statwrong1.close();
                    ofstream stataccuracy1("stataccuracy.txt");
                    stataccuracy1 << accuracy(sum1, n3);
                    stataccuracy1.close();
                    aftergamelevel3(seconds3, c, levelthree);
                    saveinfilelevel3(c, levelthree);
                    if (countcommenchars(levelthree, c) != 148) {
		   //limit the player! he/she cant go to the next level untill she/he has finished this level
                        change_color(COLOR_ORANGE_1);
                        cout << endl << endl
                             << " Sorry! you can't go to the next level until you get 5 stars in this level.";
                        cout << endl << endl << " Wait a little and then Try again ^__' ";
                        change_color(COLOR_DEFAULT);
                        timer(12);
                        level = "3";
                    } else {
                        level = "1";
			//update level num in file
                        ofstream MyFile("level.txt");
                        MyFile << level;
                        MyFile.close();
                        char continuing3;
                        cin >> continuing3;
                        clear_screen();
                        printf("\n WELL DONE ! You have finished all the levels!\n\n");
                        Press();
                        cin >> aftergaming;
                        clear_screen();

                    }
                }
            }

        }
        if (aftergaming == 1 || edame == 1 || afterstats == 1) {
            clear_screen();
            Menu();
            cin >> select;
            clear_screen();
        }
	//STATS
        if (select == 2 || aftergaming == 2 || edame == 2 || afterstats == 2 || afterquit == 2) {
            clear_screen();
            string statcorrect, statwrong, statacc;
	    //read stats from file
            ifstream statcorrects("statcorrect.txt");
            string mytext1;
            while (getline(statcorrects, mytext1)) {
                statcorrect = mytext1;
            }
            ifstream statwrongs("statwrong.txt");
            string mytext2;
            while (getline(statwrongs, mytext2)) {
                statwrong = mytext2;
            }
            ifstream stataccs("stataccuracy.txt");
            string mytext3;
            while (getline(stataccs, mytext3)) {
                statacc = mytext3;
            }
            stats(stoi(statcorrect), stoi(statwrong), stoi(statacc));
            Press();
            cin >> afterstats;

        }

	//QUIT
        if (select == 3 || aftergaming == 3 || edame == 3 || afterstats == 3 || afterquit == 3) {
            clear_screen();
            stayorleave();
            char choose;
            cin >> choose;
            if (choose == 'Y')
                quit();
            clear_screen();
            if (choose == 'N') {
                Press();
            }
        }
        cin >> edame;
    }

}




