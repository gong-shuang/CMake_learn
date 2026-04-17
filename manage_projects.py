#!/usr/bin/env python3
"""
批量管理根目录下所有独立的 CMake 项目。
用法:
    python3 manage_projects.py build    # 构建所有项目
    python3 manage_projects.py clean    # 清理所有项目的 build 目录
"""

import subprocess
import sys
import shutil
from pathlib import Path

def find_projects(root_dir: Path):
    """返回所有包含 CMakeLists.txt 的子目录列表（递归搜索，排除 build 目录）"""
    projects = []
    for cmake_file in root_dir.rglob("CMakeLists.txt"):
        project_dir = cmake_file.parent
        if "build" not in project_dir.parts:
            projects.append(project_dir)
    return projects

def build_project(project_path: Path) -> bool:
    """在项目目录中创建 build/ 并执行 CMake 配置与编译，成功返回 True"""
    print(f"\n>>> 正在构建项目: {project_path.name}")
    build_dir = project_path / "build"
    build_dir.mkdir(exist_ok=True)

    # cmake 配置
    try:
        subprocess.run(
            ["cmake", str(project_path)],
            cwd=build_dir,
            check=True,
            capture_output=True,
            text=True
        )
    except subprocess.CalledProcessError as e:
        print(f"   [错误] CMake 配置失败 in {project_path.name}")
        print(e.stderr)
        return False

    # cmake 编译
    try:
        subprocess.run(
            ["cmake", "--build", "."],
            cwd=build_dir,
            check=True,
            capture_output=True,
            text=True
        )
    except subprocess.CalledProcessError as e:
        print(f"   [错误] 编译失败 in {project_path.name}")
        print(e.stderr)
        return False

    print(f"   ✓ {project_path.name} 构建成功")
    return True

def clean_project(project_path: Path) -> None:
    """删除项目目录下的 build/ 文件夹"""
    build_dir = project_path / "build"
    if build_dir.exists():
        print(f"删除: {build_dir}")
        shutil.rmtree(build_dir)
    else:
        print(f"跳过 (build 不存在): {build_dir}")

def main():
    if len(sys.argv) != 2 or sys.argv[1] not in ("build", "clean"):
        print(__doc__)
        sys.exit(1)

    action = sys.argv[1]
    root_dir = Path(__file__).parent.resolve()
    print(f"根目录: {root_dir}")

    projects = find_projects(root_dir)
    if not projects:
        print("未找到任何包含 CMakeLists.txt 的子目录。")
        sys.exit(0)

    print(f"发现 {len(projects)} 个 CMake 项目: {', '.join(p.name for p in projects)}")

    if action == "build":
        failed = []
        for proj in projects:
            if not build_project(proj):
                failed.append(proj.name)
        print("\n" + "=" * 40)
        if failed:
            print(f"构建失败的项目: {', '.join(failed)}")
            sys.exit(1)
        else:
            print("所有项目构建成功！")
    elif action == "clean":
        for proj in projects:
            clean_project(proj)
        print("清理完成。")

if __name__ == "__main__":
    main()