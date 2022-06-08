using Xunit;
using ScrumBoard.Body;

namespace ScrumTest
{
    public class ColumnsTest
    {
        private string TrialTitle = "Column title";
        private string TrialTaskTitle = "Task title";
        private string TrialDescription = "Description";
        private Task_priority TrialPriority = Task_priority.MEDIUM;

        [Fact]
        public void Create_columnToBoard()
        {
            ColumnI column = TrialColumn();

            Assert.Equal(TrialTitle, column.Title);
            Assert.Empty(column.Find_tasks());
        }

        [Fact]
        public void RemoveTaskFromColumn()
        {

            ColumnI column = TrialColumn();
            TaskId task = TrialTask();
            column.Add_task(task);

            column.Delete_task_by_title(task.Title);

            Assert.Empty(column.Find_tasks());
        }

        [Fact]
        public void Add_taskToColumnInBoard()
        {

            ColumnI column = TrialColumn();
            TaskId task = TrialTask();

            column.Add_task(task);

            Assert.Collection(column.Find_tasks(),
            columnTask => Assert.Equal(task, columnTask));
        }

        [Fact]
        public void ChangeColumnTitleInBoard()
        {

            ColumnI column = TrialColumn();
            string newTitle = "Updated";

            column.Title = newTitle;

            Assert.Equal(newTitle, column.Title);
        }

        private ColumnI TrialColumn()
        {
            return Creator.Create_column(TrialTitle); ;
        }

        private TaskId TrialTask()
        {
            return Creator.Create_task(TrialTaskTitle, TrialDescription, TrialPriority);
        }
    }
}
