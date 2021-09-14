
#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
#include <string.h>

/*
to add manual page
create file named
gedit task.1
then convert it to gzip file using
gzip task.1
them move/copy it manul pages directory of linux using root acces and
sudo cp task.1.gz /usr/share/man/man1
tray call man cmd followed by the name of the project
man task
*/

void details();

int main (int argc  ,char *argv[])
{
	 //compare first input and --help ,if they are equals

if(argc>1){

	if (strcmp(argv[1],"--help")==0)
	{
     	        details();
		return 0;
	}

	printf("Hello in System Manager\n");
}
else{

	 //initilization part
	 int ch;//first choice
	 int ch2;//second choice
	int y;//1 for Yes or 0 No
	 char  name[200];
	 char  name2[200] ;
	 char  name3[200];
	int d;//num of days
	//some strings for strcat function
	char  m1 [200];
	char  m2[200] ;
	char  m3 [200];
	char  m4  [200];


		//gets();  //to get input type String
		//strcat(str1,str2);  ///to merge str1+str2
         //gets();
		 //strcat(  ,  );

    do
    {
    printf("1.Add User\n");
	printf("2.Delete User\n");
	printf("3.Add Group\n");
	printf("4.Delete Group\n");
	printf("5.Modifey User info\n");
	printf("6.change account info (password expiration)\n");
	printf("7.Assign user To Group\n");
		//take your choice
	scanf("%d",&ch);

//switch(ch)
//if(ch>0 && ch<8)
//{
	//##list all users
//case 1:
//case 2:

if(ch==1 || ch==2)
{
printf("1.show List of all users\n");
printf("2.add new user\n");
printf("3.delete existing user\n");
printf("4.Create a New User and Assign Groups in One Command\n");
printf("5.Display User Groups by name\n");
		scanf("%d",&ch2);
			if(ch2==1)
	 system("cat /etc/group"  );
	//	system("ls"  );


		if(ch2==2)
		{
		printf("Enter UserName \n");
		scanf("%s",&name);
        char cmd[200]="sudo adduser ";
 		strcat(cmd,name);
		system(cmd);
		}



			if(ch2==3)
			{

		printf("Enter → UserName (delete  that user's home directory and mail\n");
		scanf("%s",&name);
        char cmd[200]="sudo userdel -r ";
 		strcat(cmd,name);

 		system(cmd);
			}


 if(ch2==4)

			{
        printf("Enter PrimeryGroupName → SeconderyGroupName →UserName \n");
        scanf("%s",&name);
        scanf("%s",&name2);
        scanf("%s",&name3);
        char cmd[200]="sudo useradd -g ";
 		//##############strcat(cmd,name);

		strcat(cmd,name);
		strcat(cmd," -G ");
		strcat(cmd,name2);
		strcat(cmd," ");
		strcat(cmd,name3);

 		system(cmd);




 	//system("sudo useradd -g %c -G %c  %c",name,name2,name3);



			 //end switch  ch2 for case 1
			}
if(ch2==5)
{
		printf("enter name \n");
		scanf("%s",&name);
        char cmd[200]="id ";
 		strcat(cmd,name);

 		system(cmd);
	//system("id %c",name);
}

}

else if(ch==3)
{
	    printf("Enter New Group Name:\n");
 		scanf("%s",&name);
        char cmd[200]="sudo groupadd ";
 		strcat(cmd,name);

 		system(cmd);
					printf("group created\n");

       //system(" %c",name);

}

else if(ch==4)
{
	printf("Enter Group Name to Delete:\n");
    scanf("%s",&name);
    char cmd[200]="sudo groupdel ";
    strcat(cmd,name);
    system(cmd);
			printf("group deleted\n");

		//system("sudo groupdel groupname %c",name);

}
else if(ch==5)
{
				printf("choice to Edit \n");
				printf("1  .change the user login name \n");
				printf("2  .Get user id by name \n");
				printf("3  .Remove a User From a Group \n");
				printf("4  .change the user ID for a user. \n");
				printf("5  .Modify the group ID of a user. \n");
				scanf("%d",&ch2);
		if(ch2==1)


		{

			printf("Enter  new_login_name → old_login_name\n");
			scanf("%s",&name);
			scanf("%s",&name2);
    char cmd[200]="sudo usermod -l ";
    strcat(cmd,name);
    strcat(cmd," ");
    strcat(cmd,name2);
    system(cmd);





       //  system("sudo usermod -l %c  %c",name,name2);

		}
		if(ch2==2)

		{
            //char aa[200]="root";
            printf("enter name \n");
            scanf("%s",&name);
            char cmd[200]="id ";
            strcat(cmd,name);

            system(cmd);


			//system("id username");


		}

		if(ch2==3)
		{
		printf("Enter UserName → GroupName  \n");
			scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="sudo gpasswd -d  ";
            strcat(cmd,name);
            strcat(cmd," ");
        //#############################
            strcat(cmd,name2);

            system(cmd);


      //   system("sudo gpasswd -d %c %c ",name,name2);
 		}
			if(ch2==4)
		{
		printf("Enter  newID → UserName   \n");
            scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="usermod -u ";
            strcat(cmd,name);
            strcat(cmd," ");
            strcat(cmd,name2);

            system(cmd);

		//system("usermod  -u %c %c",name,name2);

		}
		if(ch2==5)
		{
		printf("Enter  new_group_id → UserName   \n");
			scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="usermod -g ";
            strcat(cmd,name);
            strcat(cmd," ");
            strcat(cmd,name2);

            system(cmd);

         //system("usermod -g  %c %c",name,name2);

		}





}


//***
else if(ch==6)
{
printf("choice \n");
printf("1.Manage User Password Expiration and Aging\n");
printf("2.set the date or number of days to account\n");
printf("3.set the number of days of warning before a password change is required.\n");
printf("4. set the number of days of inactivity after a password has expired before the account is locked.\n");



       scanf("%d",&ch2);
		if(ch2==1)
		{

		printf("Enter → UserName\n");
		scanf("%s",&name);

            char cmd[200]="chage -l ";
            strcat(cmd,name);


            system(cmd);

		//system("chage -l useName",name);
		}

			if(ch2==2)
			{
			printf("Date → userName\n");
			scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="chage -E ";
            strcat(cmd,name);
            strcat(cmd," ");
            //############################################
            strcat(cmd,name2);

            system(cmd);

			//system("chage -E %c %c",name,name2);

			}

		if(ch2==3)
			{
            printf("num → userName\n");
            scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="chage -W ";
            strcat(cmd,name);
            strcat(cmd," ");
            //############################
            strcat(cmd,name2);

            system(cmd);

		//system("chage -W %c %c",d,name);
			}

		if(ch2==4)
		{
            printf("num → userName\n");
            scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="chage -I ";
            strcat(cmd,name);
            strcat(cmd," ");
            //#####################
            strcat(cmd,name2);

            system(cmd);

		//system("chage -I %c %c",d,name);

		}


		}


 else
  //if  (ch==7);
{
	 //assign user to group

		printf("1.Add an Existing User to a Group or Secondery Group\n");
		printf("2.Add an Existing User to Multiple Groups in One Command\n");
        scanf("%d",&ch2);
		if(ch2==1)
		{

		    printf("Enter  GroupName →  UserName  \n");
		    scanf("%s",&name);
			scanf("%s",&name2);
            char cmd[200]="sudo usermod -a -G ";
            strcat(cmd,name);
            strcat(cmd," ");
		//#################3
            strcat(cmd,name2);

            system(cmd);


            //usermod -a -G examplegroup exampleusername

		}


		if(ch2==2)
		{
            printf("Enter group1 →  group2 →   UserName \n");
            scanf("%s",&name);
			scanf("%s",&name2);
			scanf("%s",&name3);
            char cmd[200]="sudo usermod -a -G ";
            strcat(cmd,name);
            strcat(cmd,",");
            strcat(cmd,name2);
            strcat(cmd," ");
            strcat(cmd,name3);

            system(cmd);

		//system("sudo usermod -a -G %c,%c %c",name2,name,name3);
		}

    }//end if 7
    //*/





             printf("DO u want to run again (Yes(1)/No(0)?\n");
//}//end if ch
  scanf("%d",&y);
    }//end do loop

    while (y!=0);

           /* printf("DO u want to run again (Y/N)?\n");
        scanf("%c",&y);
}
//end do loop
//   while (printf("HHH"),scanf("%d",&y)==1);

	//while (printf("DO u want to run again (Y/N)?\n"),scanf("%d",&y)==1);
	while (y=='y');


*/

return 0;

}
}

 void details()
{
//Read from help.txt to show the help page
	//printf("--Help");
	//Note we cant assign string in char[] exipt in decelration part
   FILE *fp;
    char ch;
    char file_name[50]="help1.txt";
   //gets(file_name);

   fp = fopen(file_name, "r"); // read mode

/*   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
*/
   printf("The help of %s file are:\n", file_name);

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
}



/*
strlen(s1): returns the length of a string.
strcpy(s1, s2): copies string s2 to s1
strrev(s1): reverses the given string
strcmp(s1, s2): returns 0 if s1 and s2 contain the same string.
strcat(s1, s2): concatenates two strings
*/

