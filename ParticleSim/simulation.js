/**
 * Simulation logic for the particle sim.
 */

var lastUpdate = new Date();

var edges = [
        { normal: { x: 1, y: 0 }, distance: 1 },
        { normal: { x: 0, y: -1 }, distance: 1 },
        { normal: { x: -1, y: 0 }, distance: 1 },
        { normal: { x: 0, y: 1 }, distance: 1 }
    ]

function update() {
    var now = new Date();
    var elapsed = now - lastUpdate;
    for (var i = 0; i < world.children.length; ++i) {
        var child = world.children[i];
        if (child.move !== undefined) {
            child.move(elapsed);
            collide(child);
        }
    }
    lastUpdate = now;
}

function collide(child) {
    for (var i = 0; i < edges.length; ++i) {
        var edge = edges[i];
        var edgepixeldist = Math.max(world.width, world.height) * edge.distance / 2
        // convert the coordinates such that the origin is in the center
        // of the world, it's easier to calculate the distance this way
        var dotproduct = (child.x - world.width/2) * edge.normal.x + (child.y - world.height/2) * edge.normal.y
        var distance = dotproduct + edgepixeldist;
        if (distance < 0) {
            // collision
            var dotvel = child.xvel * edge.normal.x + child.yvel * edge.normal.y
            if (dotvel < 0) {
                // traveling "into" edge
                child.xvel -= 2 * edge.normal.x * dotvel;
                child.yvel -= 2 * edge.normal.y * dotvel;
            }
            child.x += distance * edge.normal.x;
            child.y += distance * edge.normal.y;
        }
    }
}
