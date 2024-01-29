import { useState } from "react";
import { Header } from "../components/Header";
import { Task } from "../components/Task";
import { VoidList } from "../components/VoidList";
import { withSSRAuth } from "../utils/withSSRAuth";
import { useTask } from "@/hooks/useTask";

export default function Home() {
  const {
    tasks,
    handleNewTask,
    completes,
    handleToggleTaskCompletion,
    deleteTask,
  } = useTask();

  return (
    <>
      <Header />
      <main className="w-full">
        <form
          onSubmit={handleNewTask}
          className="w-4/6 m-auto py-3 flex mb-6 space-x-2"
        >
          <input
            required
            className="w-4/5 bg-box text-sm outline-0 py-2 px-3 text-white placeholder:text-gray-600 rounded-md placeholder:text-sm"
            type="text"
            placeholder="Adicione uma tarefa..."
          />
          <button
            type="submit"
            className="flex-1 rounded-md bg-blue text-white hover:bg-sky-600 transition-colors"
          >
            Criar
          </button>
        </form>

        {tasks.length > 0 && (
          <header className="w-4/6 m-auto flex justify-between items-center mb-2">
            <div className="text-xs space-x-1">
              <span className="text-blue">Tarefas Criadas</span>
              <span className="p-1 text-white bg-box rounded-md">
                {tasks.length}
              </span>
            </div>

            <div className="text-xs space-x-1">
              <span className="text-blue">Concluídas</span>
              <span className="p-1 text-white bg-box rounded-md">
                {completes.length} de {tasks.length}
              </span>
            </div>
          </header>
        )}

        {tasks.map((task) => {
          if (tasks.length > 0) {
            return (
              <Task
                key={task.id}
                id={task.id}
                task={task}
                onDeleteTask={deleteTask}
                handleToggleTaskCompletion={handleToggleTaskCompletion}
              />
            );
          }
        })}

        <div>{tasks.length === 0 && <VoidList />}</div>
      </main>
    </>
  );
}
export const getServerSideProps = withSSRAuth();