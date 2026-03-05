def generate_files():
    # 定义基础数值1e5（即100000）
    base_value = 100000
    # 循环生成1到10的.in和.out文件
    for x in range(1, 11):
        # 计算每个文件要写入的内容
        content = str(base_value + x)
        
        # 生成.in文件
        try:
            with open(f"{x}.in", "w", encoding="utf-8") as f_in:
                f_in.write(content)
            # 生成.out文件
            with open(f"{x}.out", "w", encoding="utf-8") as f_out:
                f_out.write(content)
            print(f"成功生成 {x}.in 和 {x}.out 文件")
        except Exception as e:
            print(f"生成 {x}.in/{x}.out 时出错: {e}")

if __name__ == "__main__":
    generate_files()
    print("所有文件生成完成！")
