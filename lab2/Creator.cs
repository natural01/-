namespace ScrumBoard.Body
{
    public class Creator
    {
        public static BoardI Create_board(string title) 
        {
            return new Board(title);
        }

        public static ColumnI Create_column(string title)
        {
            return new Column(title);
        }

        public static TaskId Create_task(string title, string description, Task_priority priority) 
        {
            return new Body.Task(title, description, priority);
        }
    }
}