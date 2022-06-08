using Xunit;
using ScrumBoard.Creator;
using ScrumBoard.Body;
using ScrumBoard.MaximumColumns;

namespace ScrumTest
{
    public class BoardTest
    {
        private string TrialTitle = "Board Title";
        private string TrialColumnTitle = "Column Title";
        private string TrialTaskTitle = "Task Title";
        private string TrialDescription = "Description";
        private TaskPriority TrialPriority = TaskPriority.MEDIUM;
        private IBoard TrialBoard()
        {
            return Creator.CreateBoard(TrialTitle);
        }

        private IColumn TrialColumn()
        {
            return Creator.CreateColumn(TrialColumnTitle);
        }

        private ITask TrialTask()
        {
            return Creator.CreateTask(TrialTaskTitle, TrialDescription, TrialPriority);
        }

        [Fact]
        public void IfCountOfColumnsMoreThan10()
        {

            IBoard board = TrialBoard();

            for (int n = 0; n < 10; n++)
            {
                board.AddColumn(Creator.CreateColumn(n.ToString()));
            }

            Assert.Throws<Maximum_columns>(() => board.AddColumn(TrialColumn()));
        }

        [Fact]
        public void CreateBoard()
        {
            IBoard board = TrialBoard();

            Assert.Equal(TrialTitle, board.Title);
        }

        [Fact]
        public void FindColumnByTitleOnBoard()
        {

            IBoard board = TrialBoard();
            IColumn column = TrialColumn();

            board.AddColumn(column);

            Assert.Equal(column, board.FindColumnByTitle(column.Title));
        }

        [Fact]
        public void DeleteTaskFromColumn()
        {

            IBoard board = TrialBoard();
            IColumn column = TrialColumn();
            board.AddColumn(column);
            ITask task = TrialTask();
            column.AddTask(task);

            board.DeleteTask(task.Title);

            Assert.Empty(column.FindTasks());
        }
        [Fact]
        public void MoveTasksOnBoard()
        {

            IBoard board = TrialBoard();
            IColumn column_Number1 = Creator.CreateColumn("Number1");
            IColumn column_Number2 = Creator.CreateColumn("Number2");
            board.AddColumn(column_Number1);
            board.AddColumn(column_Number2);
            ITask task = TrialTask();
            board.AddTaskToColumn(task);

            board.MoveTask(task.Title);

            Assert.Empty(column_Number1.FindTasks());
            Assert.Collection(column_Number2.FindTasks(),
            column_Task => Assert.Equal(task, column_Task));
        }

    }
}