import { useForm } from "react-hook-form";
import { withoutSSRAuth } from "../../utils/withoutSSRAuth";
import { useContext } from "react";
import { AuthContext } from "@/contexts/AuthContext";

export default function Login() {
    const { register, handleSubmit } = useForm();

    const { signUp } = useContext(AuthContext);

    async function handleSignUp(data) {
        await signUp(data);
    }

    return (
        <div className="w-scree h-screen flex items-center justify-center">
            <form
                className="space-y-4 md:space-y-6 w-96"
                onSubmit={handleSubmit(handleSignUp)}
            >
                <div>
                    <label
                        htmlFor="name"
                        className="block mb-2 text-sm font-medium text-gray-900 dark:text-white"
                    >
                        Nome
                    </label>
                    <input
                        type="name"
                        name="name"
                        id="name"
                        className="bg-gray-50 border border-gray-300 text-gray-900 sm:text-sm rounded-lg focus:ring-primary-600 focus:border-primary-600 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
                        placeholder="Henrique"
                        required=""
                        {...register("name")}
                    />
                </div>
                <div>
                    <label
                        htmlFor="email"
                        className="block mb-2 text-sm font-medium text-gray-900 dark:text-white"
                    >
                        Email
                    </label>
                    <input
                        type="email"
                        name="email"
                        id="email"
                        className="bg-gray-50 border border-gray-300 text-gray-900 sm:text-sm rounded-lg focus:ring-primary-600 focus:border-primary-600 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
                        placeholder="name@company.com"
                        required=""
                        {...register("email")}
                    />
                </div>
                <div>
                    <label
                        htmlFor="password"
                        class="block mb-2 text-sm font-medium text-gray-900 dark:text-white"
                    >
                        Senha
                    </label>
                    <input
                        type="password"
                        name="password"
                        id="password"
                        placeholder="••••••••"
                        className="bg-gray-50 border border-gray-300 text-gray-900 sm:text-sm rounded-lg focus:ring-primary-600 focus:border-primary-600 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
                        required=""
                        {...register("password")}
                    />
                </div>

                <button
                    type="submit"
                    className="w-full text-white bg-blue hover:opacity-90 focus:ring-4 focus:outline-none focus:ring-primary-300 font-medium rounded-lg text-sm px-5 py-2.5 text-center dark:bg-primary-600 dark:hover:bg-primary-700 dark:focus:ring-primary-800"
                >
                    Login
                </button>
                <p class="text-sm font-light text-gray-500 dark:text-gray-400">
                    Ainda não possui uma conta?{" "}
                    <a
                        href="#"
                        className="font-medium text-primary-600 hover:underline dark:text-primary-500"
                    >
                        Cadastre-se
                    </a>
                </p>
            </form>
        </div>
    );
}
export const getServerSideProps = withoutSSRAuth();