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

var particle_counter = 1;

function initialize() {
    //particle_component = Qt.createComponent("Particle.qml");
}

function create_random_particles(count) {
    for (var i = 0; i < count; ++i) {
        create_random_particle();
    }
}

function create_random_particle() {
    var particle = Qt.createQmlObject('import Physics 1.0; Particle { }', world, "randomParticle" + particle_counter++);
    particle.x = random_world_coordinate();
    particle.y = random_world_coordinate();
    particle.xvel = random_velocity_component();
    particle.yvel = random_velocity_component();
    particle.color = random_color();
    console.log("Created particle at", particle.x, ",", particle.y);
}

function update() {
    var now = new Date();
    var elapsed = now - lastUpdate;
    for (var i = 0; i < world.children.length; ++i) {
        var child = world.children[i];
        if (child.move !== undefined) {
            child.move(elapsed);
            collide(child);
        } else {
            console.log("Child", child, "doesn't support move");
        }
    }
    lastUpdate = now;
}

function collide(child) {
    collide_from_particles(child);
    collide_from_edges(child);
}

function collide_from_particles(child) {
    for (var i = 0; i < world.children.length; ++i) {
        var other = world.children[i];
        if (other === child) {
            continue;
        }
        var vector = { x: other.x - child.x, y: other.y - child.y };
        var distance = Math.sqrt(Math.pow(vector.x, 2) + Math.pow(vector.y, 2));
        var normal = { x: vector.x / distance, y: vector.y / distance };
        var overlap = distance - (child.radius + other.radius);
        if (overlap < 0) {
            // particle-particle collision
            child.x += overlap * normal.x;
            child.y += overlap * normal.y;
            var vrelative = { x: child.xvel - other.xvel, y: child.yvel - other.yvel };
            var vrel_dot_nor = vrelative.x * normal.x + vrelative.y * normal.y;
            var impulse = { x: normal.x * vrel_dot_nor, y: normal.y * vrel_dot_nor };
            child.xvel -= impulse.x;
            child.yvel -= impulse.y;
            other.xvel += impulse.x;
            other.yvel += impulse.y;
        }
    }
}

function collide_from_edges(child) {
    for (var i = 0; i < edges.length; ++i) {
        var edge = edges[i];
        var edgepixeldist = Math.max(world.width, world.height) * edge.distance / 2
        // convert the coordinates such that the origin is in the center
        // of the world, it's easier to calculate the distance this way
        var dotproduct = (child.x - world.width/2) * edge.normal.x + (child.y - world.height/2) * edge.normal.y
        var distance = dotproduct + edgepixeldist - child.radius;
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

function random_world_coordinate() {
    return Math.floor(Math.random() * world.width);
}

function random_velocity_component() {
    return Math.floor(Math.random() * ((world.width + world.height)/2)/2);
}

function random_color() {
    return Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
}
