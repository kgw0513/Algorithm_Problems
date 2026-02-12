package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var s string

	for {
		_, err := fmt.Fscan(r, &s)
		
		if err != nil {
			break
		}

		switch s {
		case "animal":
			fmt.Fprintln(w, "Panthera tigris")
		case "tree":
			fmt.Fprintln(w, "Pinus densiflora")
		case "flower":
			fmt.Fprintln(w, "Forsythia koreana")
		default:
			return 
		}
	}
}