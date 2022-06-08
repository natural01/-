using Xunit;
using ScrumBoard.Creator;
using ScrumBoard.Body;

namespace ScrumTest
{
    public class TaskTests
    {
        private ITask TrialTask()
        {
            return Creator.CreateTask(TrialTitle, TrialDescription, TrialPriority);
        }
        private string TrialTitle = "Title";
        private string TrialDescription = "Description";
        private TaskPriority TrialPriority = TaskPriority.MEDIUM;

        [Fact]
        public void CreateTaskToColumn()
        {

            ITask task = TrialTask();



            Assert.Equal(TrialTitle, task.Title);
            Assert.Equal(TrialDescription, task.Description);
            Assert.Equal(TrialPriority, task.Priority);
        }

        [Fact]
        public void Rename_task_title()
        {

            ITask task = TrialTask();
            string newTitle = "Updated";

            task.Title = newTitle;

            Assert.Equal(newTitle, task.Title);
        }

        [Fact]
        public void ChangeTaskPriority()
        {

            ITask task = TrialTask();
            TaskPriority newPriority = TaskPriority.HARD;

            task.Priority = newPriority;

            Assert.Equal(newPriority, task.Priority);
        }

        [Fact]
        public void RenameTaskDescription()
        {
            ITask task = TrialTask();
            string newDescription = "Updated";

            task.Description = newDescription;

            Assert.Equal(newDescription, task.Description);
        }
    }
}