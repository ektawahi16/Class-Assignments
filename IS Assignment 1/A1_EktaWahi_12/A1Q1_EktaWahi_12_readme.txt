Input: The Number of Steps HoneyBee can move.


Output:
1.Expectation(Mean) of the Displacement of the HoneyBee from the Initial Position.
2.Standard Deviation of the Displacement of the HoneyBee from the Initial Position.


Design:
A 2-D plane with random initial (x,y) coordinates of the HoneyBee.


Main Variables Initialized:
->initial_x and initial_y-It stores the initial (x,y) coordinates of the HoneyBee.
                                   These are generated randomly.
->current-x and current_y-It stores the current (x,y) coordinates of the HoneyBee.
                                      These are calculated at each move.
->final_x and final_y-It stores the final (x,y) coordinates of the HoneyBee.
                               These are calculated at the end of each iteration.
->displacement[ ]-It an array to store the displacement of the HoneyBee at the
                          end of each iteration.
->expectation-It stores the mean expectation of the distance of the HoneyBee
                     after N steps for 100 iterations.
->Standard_deviation-It stores the standard deviation of the distance of the
                                 HoneyBee after N steps for 100 iterations. 


Concept:
The Bee can move in six directions:
1)Direction 1-North
 New coordinates will be (x,y+1).
2)Direction 2-North East
 New coordinates will be (x+(sqrt(3)*0.5),y+0.5).
3)Direction 3-South East
 New coordinates will be (x+(sqrt(3)*0.5),y-0.5).
4)Direction 4-South
 New coordinates will be (x,y-1).
5)Direction 5-South West
 New coordinates will be (x-(sqrt(3)*0.5),y-0.5).
6)Direction 6 North West
 New coordinates will be (x-(sqrt(3)*0.5),y+0.5).

The direction of the HoneyBee is chosen randomly.After N steps, the displacement 
of the honeyBee is calculated using euclidean distance formula.
