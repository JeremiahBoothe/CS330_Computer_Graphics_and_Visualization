# CS_330_3D_Scene

[Project Reflection](#Project-Reflection)
- [How do I approach designing software?](#How-do-I-approach-designing-software?)
	- [What new design skills has your work on the project helped you to craft?](#What-new-design-skills-has-your-work-on-the-project-helped-you-to-craft?)
	- [What design process did you follow for your project work?](#What-design-process-did-you-follow-for-your-project-work?)
	- [How could tactics from your design approach be applied in future work?](#How-could-tactics-from-your-design-approach-be-applied-in-future-work?)
- [How do I approach developing programs?](#How-do-I-approach-developing-programs?)
	- [What new development strategies did you use while working on your 3D scene?](#What-new-development-strategies-did-you-use-while-working-on-your-3D-scene?)
	- [How did iteration factor into your development?](#How-did-iteration-factor-into-your-development?)
	- [How has your approach to developing code evolved throughout the milestones, which led you to the project’s completion?](#How-has-your-approach-to-developing-code-evolved-throughout-the-milestones,-which-led-you-to-the-project’s-completion?)
- [How can computer science help me in reaching my goals?](#How-can-computer-science-help-me-in-reaching-my-goals?)
	- [How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future educational pathway?](#How-do-computational-graphics-and-visualizations-give-you-new-knowledge-and-skills-that-can-be-applied-in-your-future-educational-pathway?)
	- [How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future professional pathway?](#How-do-computational-graphics-and-visualizations-give-you-new-knowledge-and-skills-that-can-be-applied-in-your-future-professional-pathway?)

# **Project Reflection**

## How do I approach designing software?
### What new design skills has your work on the project helped you to craft?
It helped me start to bridge the gap between Linear Algebra, pixels on a screen, and what that looks like in code. Now I can combine the three in a more meaningful way and there are less barriers separating the different concepts. I haven't quite figured out how that builds on my design process with more functional code, but I am a lot more comfortable with being able to translate visual ideas into the components that represent them mathematically and syntactically.

### What design process did you follow for your project work?
My first step is jumping in and making some guesses to gauge how far off my initial intuitions are. During this period I make an absolute mess because I want to try to see how far I can go before it all collapses. With some good version control, this isn't an issue as I can always revert if I get too far off track. This helps me find a starting point and develop some understanding of the inner workings of the code. Somewhat like flipping a switch and realizing that up turns the light on and down turns it off. During this process I read a lot of documentation. I'm a big fan of "Cheat-Sheets", that are a few well organized pages of a list of the functions, the arguments they take, their type, and a short description of the purpose in the program. There is a really nicely organized document for OpenGL. When that doesn't provide enough information I can always go to the developer docs for more lengthy descriptions.

Once I hit a point where I have a broader understanding, I start creating UML diagrams. This helps me keep track of how various classes and functions work together to achieve a goal. It's also easily expandable and as I gain more familiarity and have new Ideas I can fit in more class diagrams and functions, color code them and turn it into a more comprehensive reference that gives me a lot of information in a quick glance.

### How could tactics from your design approach be applied in future work?
It's my process, I can't really design something I know nothing about. With unfamiliar things, that trial and error helps me formulate the questions and seek out their answers.


## How do I approach developing programs?
Much like my design process, but as a program innevitably expands I try to find ways to refactor and reduce redundancy. Of course this isn't always an easy task nor does it always end in a better outcome. Sometimes the abstractions create more problems and end up being more difficult to manage than leaving the redundancies.


### What new development strategies did you use while working on your 3D scene?
My strategy was to take the long route and do things the hard way all the way through. Once a problem is solved it becomes much easier to duplicate and modify it for closely related problems. Sometimes that would mean a few days with no meaningful progress or a complete reset to an earlier working state. Once I was successful I had a deeper understanding of why I was successful and could reuse what I learned to make up for any time lost. Manually wrapping a cube on all sides with a single that represented four different sides, took 2-3 days the first time. After that, I could set up a new cube and wrap it in about an hour, at that point creating the textures was the most time consuming part. That strategy sums up the term. Same with normals, there were easier ways, but the long way gave me enough understanding to create functions that could handle the calculations and reduce my own workload.


### How did iteration factor into your development?
Iteration plays a huge factor, it's one thing to copy and modify solutions from tutorials and other code, and while I'm less inclined to iterate on something I immediately understand well, I iterate a lot on code that I'm only barely grasping so I can reach a point where I write it with full intent and understanding of the purpose behind my choices. Sometimes that just means I delete things because I realized there was no point to include that code and I had only done so because someone else did it.  Many of those rewrites ended in failures and resulted in resetting the project to an earlier state and working forward again. For every line that is currently in the project, there were probably 10 more written and erased because they didn't move me toward the goal I was trying to achieve. Even some of the successes turned out to not put me in a better position than I had started.

### How has your approach to developing code evolved throughout the milestones, which led you to the project’s completion?
I don't think it evolved much to be honest, but it did give me a chance to really exercise that process on some very challenging concepts and push my ability to solve problems to a level that I'd rarely come close to previously. I would need a few more months of dedicated OpenGL time to evolve my development process as I feel that I didn't fully get to go through what I would consider a full cycle as the concepts and problems were so challenging that I'm mostly just happy that I got what I did to work.  And it looks pretty awesome!  Trying to find one good adjustment to my process, I think I could have done a better job proiritizing from the start. I did end up trying to go down several different pathways at once in an attempt to try out many things, and sometimes I got more caught up in some of the less important features I wanted to implement which took some time away from elements that were more of a priority. I did underestimate the challenge a bit or maybe over-estimated my own abilities, but I essentially applied what would have been reasonably a 4-6 month development process into a 2 month time frame.

## How can computer science help me in reaching my goals?
My goal is to be a software engineer. I know what it means in a technical sense, but I still don't know what that means for me personally. Every new class and every new concept shows me another possible path, and a lot of them are very interesting. Sometimes I wish I could duplicate myself like Dr. Manhattan and explore all pathways simultaneously, but since that's not currently possible I just keep learning and in a year I graduate, then I get to go through the next big challenge of finding the best fit to start my new career.

### How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future educational pathway?
For the rest of my Bachelor's, I don't really know what's in store for me.  I am more comfortable with working closer to a hardware level and with C++. If I end up pursuing a Masters degree my top choices are Machine Learning and Computer Vision, or some combination of the two. It will be in the back of my mind for many of the classes even if it's not something I get to apply directly.  When I get to mobile development in a couple of terms I'm going to be looking more at OpenGLES, and I will be looking into WebGL when I get to full stack development. Time and prioritizing the classes over my own interests might prevent me from spending the time I'd like to with them but looking at something is the first step to understanding it.

### How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future professional pathway?
It really depends on what type of career path I end up on. Game programming, computer vision, machine learning, and Android development are top picks for me. Within all of those there's plenty of room for having strong skills in GPU programming. Even Machine learning with LLM's running on GPU's, even if it's not about creating AI directly but building and optimizing the code to allow it to run on a GPU efficiently.