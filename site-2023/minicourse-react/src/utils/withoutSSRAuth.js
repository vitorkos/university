import { parseCookies } from "nookies";

export function withoutSSRAuth(fn) {
    return async (ctx) => {
        const { ["todo.token"]: token } = parseCookies(ctx);

        if (token) {
            return {
                redirect: {
                    destination: "/",
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
