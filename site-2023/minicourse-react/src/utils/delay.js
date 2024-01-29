export const delay = (amount = 750) =>
    new Promise((resolve) => setTimeout(resolve, amount));