# Mayday_Game
It is a 2-d game with a plane and hills, you goal is to not hit the hills, but if you fly too high, then it would stall! Can you Survive? <br>
It was made in C++ with Simple DirectMedia Layer, No game engines involved! <br>
It has its own Pseudo Random Generator which helps with seed which generates the map i.e. same seed = same map. This is inspired from Minecraft.<br>
It is multithreaded to differentiate between rendering frames, calculating scores and time; and moving.<br>

# Rules:-
1. The plane is controlled by "w" to go up, "s" to go down.
2. Avoid the mountains, I have developed the plane to have an accurate hitbox [the wings of plane are not hitbox because they are out of the planar region].
3. Mountains are generated randomly using a 10 digit number called seed [if you have played Minecraft you will know what it is]. Later ill add a feature to try again the same map.
4. Stall is what makes you not go up too much. Stall has 3 levels, level 0 is below 70% of height, level 1 is above 70% and below 90%, level 2 is above 90%.
5. There is a stall-meter, initially its 50% full, its increases in level 0, and decreases in level 1 & 2. if stall-meter hits 0 you lose.
6. score increases by 1 every 10ms, so get the highest score [ill later add a ending and boss fight].

<div id="toc">
  <ul style="list-style: none">
    <summary>
      <h2> MAYDAY <br>
MADE BY SUBHAM CHAKRABORTY (S.BOLT) </h2>
    </summary>
  </ul>
</div>
