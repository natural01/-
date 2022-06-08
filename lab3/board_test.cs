using Xunit;
using ScrumBoard.Body;

namespace ScrumTest
{
    public class BoardTest
    {
        private string TrialTitle = "Board Title";
        private string TrialColumnTitle = "Column Title";
        private string TrialTaskTitle = "Task Title";
        private string TrialDescription = "Description";
        private Task_priority TrialPriority = Task_priority.MEDIUM;
        private BoardI TrialBoard()
        {
            return Creator.Create_board(TrialTitle);
        }

        private ColumnI TrialColumn()
        {
            return Creator.Create_column(TrialColumnTitle);
        }

        private TaskId TrialTask()
        {
            return Creator.Create_task(TrialTaskTitle, TrialDescription, TrialPriority);
        }

        [Fact]
        public void Create_board()
        {
            BoardI board = TrialBoard();

            Assert.Equal(TrialTitle, board.Title);
        }

        [Fact]
        public void Find_column_by_titleOnBoard()
        {

            BoardI board = TrialBoard();
            ColumnI column = TrialColumn();

            board.Add_column(column);

            Assert.Equal(column, board.Find_column_by_title(column.Title));
        }

        [Fact]
        public void Delete_taskFromColumn()
        {

            BoardI board = TrialBoard();
            ColumnI column = TrialColumn();
            board.Add_column(column);
            TaskId task = TrialTask();
            column.Add_task(task);

            board.Delete_task(task.Title);

            Assert.Empty(column.Find_tasks());
        }
        [Fact]
        public void MoveTasksOnBoard()
        {

            BoardI board = TrialBoard();
            ColumnI column_Number1 = Creator.Create_column("Number1");
            ColumnI column_Number2 = Creator.Create_column("Number2");
            board.Add_column(column_Number1);
            board.Add_column(column_Number2);
            TaskId task = TrialTask();
            board.Add_task_to_column(task);

            board.Move_task(task.Title);

            Assert.Empty(column_Number1.Find_tasks());
            Assert.Collection(column_Number2.Find_tasks(),
            column_Task => Assert.Equal(task, column_Task));
        }

    }
}
