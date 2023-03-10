#version 330
in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec2 resolutionNormalized;

out vec4 finalColor;

void main() {
	vec2 uv = fragTexCoord;
	vec2 nr = resolutionNormalized;
    vec4 texelColor = texture(texture0, uv)*fragColor;

	bool alive = texelColor.r != 0;
	
	int arr[] = int[](0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1);
	int count = 0;
	for (int i=0; i<8; ++i) {
		float r = (	texture(texture0,
					vec2(uv.x + arr[i*2]*nr.x, uv.y + arr[i*2 +1] *nr.y))*fragColor).r;
		count += r != 0 ? 1 : 0;
	}

	vec3 colA = vec3(1,1,1);
	vec3 colD = vec3(0,0,0);

	if (alive) {
		if (count != 2 && count != 3)
			texelColor.rgb = colD;
	} else {
		if (count == 3) texelColor.rgb = colA;
	}

    finalColor = texelColor;
}
