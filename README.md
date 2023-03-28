# Push_swap

![ezgif com-crop](https://user-images.githubusercontent.com/38796098/57738594-6b6ae500-76b0-11e9-9d29-0f59ee825e8e.gif)


## Summary
The push_swap project is a bespoke sorting algorithm written in C. It calculates and displaysthe 
instructions used to sort the integers received as arguments, such as pushing, popping, swapping and rotating them between stack a and stack b. 
Here is a table with all allowed intruction to do between both stacks.

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`
<br>
To use a visualizer like the top gif, refer directly here : https://github.com/o-reo/push_swap_visualizer
