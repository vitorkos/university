import { delay } from "@/utils/delay";

export async function signInRequest({ email }) {
    await delay();

    return {
    token: "any_token",
    user: {
        name: "Henrique",
        email,
        },
    };
}

export async function signUpRequest({ name, email, password }) {
    await delay();

    return {
    token: "any_token",
    user: {
        name: "Henrique",
        email,
        },
    };
}

export async function recoverUserInformation() {
    await delay();

    return {
    user: {
        name: "Henrique",
        email: "henrique@setupjr.com",
        },
    };
}