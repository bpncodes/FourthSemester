import java.util.Scanner;


public class Tictactoe {

    int[][] arr=new int[3][3];
    static int turn=0;

    public void newGame()
    {
        int a,b,count=0;
        while(true)
        {

            int i,j;
            Scanner scan=new Scanner(System.in);
            System.out.println("The tic tac toe now is : ");
            display();
            player();
            System.out.println("Enter the row where you want to enter your move : ");
            a=scan.nextInt();
            System.out.println("Enter the column where you want to enter your move : ");
            b=scan.nextInt();
            if(a>=3||b>=3)
            {
                while(a>=3||b>=3){
                    player();
                    System.out.println("Error enter the correct input : ");
                    System.out.println("Enter the row where you want to enter your move : ");
                    a=scan.nextInt();
                    System.out.println("Enter the column where you want to enter your move : ");
                    b=scan.nextInt();
                }
            }
            int var=arr[a][b];
            if(var==0)
            {
                if(turn%2==0)
                {
                    arr[a][b]=1;
                    checkForGame();

                }
                else
                {
                    arr[a][b]=2;
                    checkForGame();
                }

                turn++;
                check();
                newGame();
            }
            else
            {
                System.out.println("There is already an element please enter a new location: ");
                check();
                newGame();
            }


        }


    }
    void display()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
    }
    void check()
    { int i=0,j=0,count=0;
        int var;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                var=arr[i][j];
                if(var!=0)
                {
                    count++;
                }
            }
        }
        if(count==9)
        {
            System.out.println("The game is over\nThe game is :\n");
            display();
            System.exit(0);
        }
    }
    void player()
    {
        if(turn%2==0)
        {
            System.out.println("-----> Player one turn <-----\n");
        }
        else{
            System.out.println("-----> Player two turn <-----\n");
        }
    }
    void checkForGame()
    {
        if(arr[0][0]==1&&arr[0][1]==1&&arr[0][2]==1||arr[1][0]==1&&arr[1][1]==1&&arr[1][2]==1||arr[2][0]==1&&arr[2][1]==1&&arr[2][2]==1||arr[0][0]==1&&arr[1][1]==1&&arr[2][2]==1||arr[0][2]==1&&arr[1][1]==1&&arr[2][0]==1)
        {
            display();
            System.out.println("Player one won!!!");
            System.exit(0);
        }
        else if(arr[0][0]==2&&arr[0][1]==2&&arr[0][2]==2||arr[1][0]==2&&arr[1][1]==2&&arr[1][2]==2||arr[2][0]==2&&arr[2][1]==2&&arr[2][2]==2||arr[0][0]==2&&arr[1][1]==2&&arr[2][2]==2||arr[0][2]==2&&arr[1][1]==2&&arr[2][0]==2)
        {
            display();
            System.out.println("Player two won!!!");
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        Tictactoe first=new Tictactoe();
        first.newGame();
    }

}
