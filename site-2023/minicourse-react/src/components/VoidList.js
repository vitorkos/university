export const VoidList = () => {
    return (
        <div className="w-1/2 m-auto flex flex-col justify-center items-center pt-8">
        <img className="w-12" src="/list.png" alt="" />
        <div className="text-gray-500 text-center">
            <p className="font-bold">Você ainda não tem tarefas cadastradas</p>
            <p>Crie tarefas e organize seus itens a fazer</p>
        </div>
        </div>
    );
};