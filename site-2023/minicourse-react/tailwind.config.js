/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./src/pages/**/*.{js,ts,jsx,tsx,mdx}",
    "./src/components/**/*.{js,ts,jsx,tsx,mdx}",
    "./src/app/**/*.{js,ts,jsx,tsx,mdx}",
  ],
  theme: {
    extend: {
      colors: {
        primary: "#0D0D0D",
        bgPrimary: "#1A1A1A",
        box: "#262626",
        blue: "#1E6F9F",
      },
    },
  },
  plugins: [],
};
