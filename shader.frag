uniform sampler2D texture; // A textura original
uniform vec4 color;        // A cor que queremos aplicar

void main() {
    vec4 texColor = texture2D(texture, gl_TexCoord[0].xy);

    // Apenas aplicar a cor onde a textura não é transparente
    if (texColor.a > 0.0) {
        gl_FragColor = texColor * color; // Multiplica pela cor
    } else {
        discard; // Ignora pixels completamente transparentes
    }
}