uniform sampler2D texture;

void main()
{
    vec4 texColor = texture2D(texture, gl_TexCoord[0].xy);
    gl_FragColor = vec4(1.0, 0.0, 0.0, texColor.a);
}