import { parseCookies } from "nookies";

export function withSSRAuth(fn) {
    return async (ctx) => {
        const { ["todo.token"]: token } = parseCookies(ctx);

        if (!token) {
            return {
                redirect: {
                    destination: "/login",
                    permanent: false,
                },
            };
        }

        if (!fn) {
            return { props: {} };
        }

        return fn(ctx);
    };
}
