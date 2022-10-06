import java.util.Arrays;

public class Sudoku {

    public static void main(String[] args) {

        int[][] board={{5,3,0,0,7,0,0,0,0},
                {6,0,0,1,9,5,0,0,0},
                {0,9,8,0,0,0,0,6,0},
                {8,0,0,0,6,0,0,0,3},
                {4,0,0,8,0,3,0,0,1},
                {7,0,0,0,2,0,0,0,6},
                {0,6,0,0,0,0,2,8,0},
                {0,0,0,4,1,9,0,0,5},
                {0,0,0,0,8,0,0,7,9}};

        if (solve(board)){
            display(board);
        }else {
            System.out.println(false);}
    }

    public static boolean solve(int[][] board) {
        int n= board.length;
        int row=-1;
        int col=-1;

        boolean emptyleft=true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j]==0){
                    row=i;
                    col=j;
                    emptyleft=false;
                    break;
                }
            }
            //if you found some empty element in row ,then break
            if (!emptyleft){
                break;
            }
        }
        if(emptyleft){
            return true ;
        }

        //backtrack

        for (int num = 1; num <= 9; num++) {
            if(isSafe(board,row,col,num)){
                board[row][col]=num;
                if (solve(board)){
                    return true;
                }else{
                    board[row][col]=0;
                }
            }
        }


        return false;

    }

    private static void display(int[][] board) {

        for(int[] row:board){
            System.out.println(Arrays.toString(row));
        }
    }

    static boolean isSafe(int[][] board,int row,int col,int num){
        //check the row
        for(int i=0;i<board.length;i++){
            if(board[row][i]==num){
                return false;
            }
        }
        for(int[] rows:board){
            if(rows[col]==num){
                return false;
            }
        }


        int rowstart=row-row%3;
        int colstart=col-col%3;

        for(int r=rowstart;r<rowstart+3;r++){
            for(int c =colstart;c<colstart+3;c++){
                if(board[r][c]==num){
                    return false;
                }
            }
        }
        return true;
    }
}

