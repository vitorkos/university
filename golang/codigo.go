package main

import (
	"fmt"
	"time"
)


func factorial(n int) int {
	if n <= 0 {
		return 1
	}
	result := 1
	for i := 1; i <= n; i++ {
		result *= i
	}
	return result
}


func calculateAndPrintFactorial(n int) {
	fact := factorial(n)
	fmt.Printf("Fatorial de %d é: %d\n", n, fact)
}

func main() {
	numbers := []int{5, 3, 7, 4}

	
	for _, num := range numbers {
		go calculateAndPrintFactorial(num)
	}

	
	time.Sleep(2 * time.Second)

	fmt.Println("Programa finalizado.")
}
