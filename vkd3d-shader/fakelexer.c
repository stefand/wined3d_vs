struct hlsl_ctx;
struct vkd3d_shader_code;
struct vkd3d_shader_compile_info;
struct vkd3d_shader_message_context;

int hlsl_lexer_compile(struct hlsl_ctx *ctx, const struct vkd3d_shader_code *hlsl)
{
    return -1;
}

int preproc_lexer_parse(const struct vkd3d_shader_compile_info *compile_info,
    struct vkd3d_shader_code *out, struct vkd3d_shader_message_context *message_context)
{
    return -1;
}

struct hlsl_ir_node *hlsl_add_load_component(struct hlsl_ctx *ctx, struct list *instrs,
    struct hlsl_ir_node *var_instr, unsigned int comp, const struct vkd3d_shader_location *loc)
{
    return (void *)0;
}
