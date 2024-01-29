import { useEffect, useState } from "react";
import { parseCookies, setCookie } from "nookies";
import Router from "next/router";

import { AuthContext } from "../contexts/AuthContext";
import { recoverUserInformation, signInRequest, signUpRequest } from "../api";

export function AuthProvider({ children }) {
    const [user, setUser] = useState(null);

    const isAuthenticated = !!user;

    useEffect(() => {
        const { "todo.token": token } = parseCookies();

        if (token) {
            recoverUserInformation().then((response) => {
                setUser(response.user);
            });
        }
    }, []);

    async function signIn({ email, password }) {
        const { token, user } = await signInRequest({ email, password });

        setCookie(undefined, "todo.token", token, {
        maxAge: 60 * 60 * 1, // 1 hora
        });

        setUser(user);

        Router.push("/");
    }

    async function signUp({ name, email, password }) {
        const { token, user } = await signUpRequest({ name, email, password });

        setCookie(undefined, "todo.token", token, {
        maxAge: 60 * 60 * 1, // 1 hora
        });

        setUser(user);

        Router.push("/");
    }

    return (
        <AuthContext.Provider value={{ user, isAuthenticated, signIn, signUp }}>
        {children}
        </AuthContext.Provider>
    );
}