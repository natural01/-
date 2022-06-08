using Xunit;
using ScrumBoard.Creator;
using ScrumBoard.Body;

namespace ScrumTest
{
    public class ColumnsTest
    {
        private string TrialTitle = "Column title";
        private string TrialTaskTitle = "Task title";
        private string TrialDescription = "Description";
        private TaskPriority TrialPriority = TaskPriority.MEDIUM;

        [Fact]
        public void CreateColumnToBoard()
        {
            IColumn column = TrialColumn();

            Assert.Equal(TrialTitle, column.Title);
            Assert.Empty(column.FindTasks());
        }

        [Fact]
        public void RemoveTaskFromColumn()
        {

            IColumn column = TrialColumn();
            ITask task = TrialTask();
            column.AddTask(task);

            column.DeleteTaskByTitle(task.Title);

            Assert.Empty(column.FindTasks());
        }

        [Fact]
        public void AddTaskToColumnInBoard()
        {

            IColumn column = TrialColumn();
            ITask task = TrialTask();

            column.AddTask(task);

            Assert.Collection(column.FindTasks(),
            columnTask => Assert.Equal(task, columnTask));
        }

        [Fact]
        public void ChangeColumnTitleInBoard()
        {

            IColumn column = TrialColumn();
            string newTitle = "Updated";

            column.Title = newTitle;

            Assert.Equal(newTitle, column.Title);
        }

        private IColumn TrialColumn()
        {
            return Creator.CreateColumn(TrialTitle); ;
        }

        private ITask TrialTask()
        {
            return Creator.CreateTask(TrialTaskTitle, TrialDescription, TrialPriority);
        }
    }
}