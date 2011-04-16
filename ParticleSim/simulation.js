/**
 * Simulation logic for the particle sim.
 */

var lastUpdate = new Date();

function update() {
    var now = new Date();
    var elapsed = now - lastUpdate;
    for (var i = 0; i < world.children.length; ++i) {
        var child = world.children[i];
        if (child.move !== undefined) {
            child.move(elapsed);
        }
    }
    lastUpdate = now;
}
