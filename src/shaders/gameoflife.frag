#version 330
in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec2 resolution;
uniform float TIME;

out vec4 finalColor;

void main() {
	vec2 nr = 1.0/resolution;
	vec2 uv = gl_FragCoord.xy/resolution;
	vec4 Color = texture(texture0, uv)*fragColor;

	bool alive = Color.r == 1;

	int arr[] = int[](0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1);
	int count = 0;
	for (int i=0; i<8; ++i) {
		float r = (	texture(texture0,
					vec2(uv.x + arr[i*2]*nr.x, uv.y + arr[i*2 +1] *nr.y))*fragColor).r;
		count += r == 1 ? 1 : 0;
	}

	vec3 colA = vec3(1,1,1);
	vec3 colD = vec3(0,0,1);

	if (alive) {
		if (count != 2 && count != 3) Color.rgb = colD;
	} else {
		if (count == 3) Color.rgb = colA;
		else Color.b -= 1.0/16;
	}

	finalColor = Color;
}
