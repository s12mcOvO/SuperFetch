# SuperFetch - System Information Tool

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

SuperFetch is a fast, highly customizable system information tool written in C. Inspired by fastfetch, it displays system information in a beautiful, terminal-based interface with support for various themes and modules.

## ✨ Features | 特性

### 🚀 Fast & Lightweight | 快速轻量
- **Blazing Fast**: Optimized C code for minimal startup time
- **Low Memory Usage**: Minimal resource consumption
- **No Dependencies**: Standalone binary with no external requirements
- **Cross-Platform**: Support for multiple operating systems

### 🎨 Highly Customizable | 高度可定制
- **Themes**: Built-in themes with color customization
- **Modules**: Modular design for displaying different information
- **ASCII Art**: Custom ASCII art and logos
- **Layout Control**: Flexible positioning and formatting options

### 📊 Comprehensive Information | 全面信息显示
- **System Info**: OS, kernel, uptime, packages
- **Hardware**: CPU, GPU, memory, disk, network
- **Software**: Desktop environment, window manager, shell
- **Colors**: Terminal color palette display

## 🏗️ Architecture | 架构

```
SuperFetch/
├── src/               # Source code | 源代码
│   ├── main.c         # Main entry point | 主入口
│   ├── modules/       # Information modules | 信息模块
│   │   ├── cpu.c      # CPU information | CPU信息
│   │   ├── memory.c   # Memory information | 内存信息
│   │   ├── disk.c     # Disk information | 磁盘信息
│   │   ├── os.c       # OS information | 操作系统信息
│   │   └── gpu.c      # GPU information | GPU信息
│   ├── themes/        # Built-in themes | 内置主题
│   ├── ascii/         # ASCII art | ASCII艺术
│   └── utils/         # Utility functions | 工具函数
├── config/            # Configuration files | 配置文件
│   ├── config.json    # Default configuration | 默认配置
│   └── themes/        # User themes | 用户主题
├── presets/           # Configuration presets | 配置预设
└── docs/              # Documentation | 文档
```

## 🚀 Quick Start | 快速开始

### Installation | 安装

```bash
# Install SuperFetch | 安装SuperFetch
bspm install superfetch

# Or build from source | 或从源码构建
git clone https://github.com/s12mcOvO/SuperFetch.git
cd SuperFetch
make
sudo make install
```

### Basic Usage | 基本使用

```bash
# Display system information | 显示系统信息
superfetch

# Use a specific theme | 使用特定主题
superfetch --theme neon

# Display only CPU and memory info | 仅显示CPU和内存信息
superfetch --cpu --memory

# Custom ASCII art | 自定义ASCII艺术
superfetch --ascii ~/my-ascii.txt
```

### Basic Usage | 基本使用

```bash
# Start SuperFetch service | 启动SuperFetch服务
sudo systemctl start superfetch

# Check status | 检查状态
superfetch status

# View performance metrics | 查看性能指标
superfetch metrics

# Generate optimization report | 生成优化报告
sf-report
```

## 📖 Documentation | 文档

### User Guide | 用户指南
- [Installation](docs/user-guide/installation.md) - Installation instructions
- [Configuration](docs/user-guide/configuration.md) - Configuration options
- [Usage](docs/user-guide/usage.md) - Command reference
- [Troubleshooting](docs/user-guide/troubleshooting.md) - Common issues

### Developer Guide | 开发者指南
- [Architecture](docs/developer-guide/architecture.md) - System architecture
- [API Reference](docs/developer-guide/api.md) - API documentation
- [Contributing](docs/developer-guide/contributing.md) - How to contribute

### Technical Documentation | 技术文档
- [Algorithms](docs/technical/algorithms.md) - Prediction algorithms
- [Performance](docs/technical/performance.md) - Performance analysis
- [Benchmarks](docs/technical/benchmarks.md) - Benchmark results

## 🔧 Configuration | 配置

### Configuration File | 配置文件

```json
{
  "$schema": "https://raw.githubusercontent.com/s12mcOvO/SuperFetch/main/config/config.schema.json",
  "display": {
    "color": "blue",
    "separator": " → "
  },
  "modules": [
    "title",
    "separator",
    "os",
    "kernel",
    "uptime",
    "packages",
    "shell",
    "resolution",
    "de",
    "wm",
    "wm_theme",
    "theme",
    "icons",
    "font",
    "cursor",
    "terminal",
    "terminal_font",
    "cpu",
    "gpu",
    "memory",
    "swap",
    "disk",
    "battery",
    "locale",
    "break",
    "colors"
  ]
}
```

### Command Line Options | 命令行选项

```bash
# Display help | 显示帮助
superfetch --help

# Use a specific config file | 使用特定配置文件
superfetch --config ~/.config/superfetch/config.json

# Disable colors | 禁用颜色
superfetch --no-color

# Set logo | 设置logo
superfetch --logo arch

# Custom structure | 自定义结构
superfetch --structure Title:OS:Kernel:CPU
```

## 🎨 Themes & Customization | 主题与定制

### Built-in Themes | 内置主题

```bash
# List available themes | 列出可用主题
superfetch --list-themes

# Use a theme | 使用主题
superfetch --theme cyberpunk
superfetch --theme minimal
superfetch --theme rainbow
```

### Custom ASCII Art | 自定义ASCII艺术

```bash
# Use built-in logos | 使用内置logo
superfetch --logo arch
superfetch --logo debian
superfetch --logo ubuntu

# Use custom ASCII file | 使用自定义ASCII文件
superfetch --ascii ~/my-logo.txt

# Use image (if supported) | 使用图片（如果支持）
superfetch --logo ~/logo.png
```

### Module Configuration | 模块配置

SuperFetch supports various information modules:

- **System**: OS, kernel, uptime, packages
- **Hardware**: CPU, GPU, memory, disk, battery
- **Software**: Desktop environment, window manager, theme
- **Terminal**: Colors, font, cursor, terminal emulator
- **Display**: Resolution, refresh rate

### Predictive Modeling | 预测建模

```bash
# Train prediction models | 训练预测模型
superfetch train

# Test prediction accuracy | 测试预测准确性
superfetch test-predictions

# Update learning models | 更新学习模型
superfetch update-models
```

## 🔧 Development | 开发

### Building from Source | 从源码构建

```bash
# Clone repository | 克隆仓库
git clone https://github.com/s12mcOvO/SuperFetch.git
cd SuperFetch

# Build kernel modules | 构建内核模块
make modules

# Build user tools | 构建用户工具
make tools

# Install | 安装
sudo make install
```

### Testing | 测试

```bash
# Run unit tests | 运行单元测试
make test

# Run integration tests | 运行集成测试
make test-integration

# Performance benchmarking | 性能基准测试
make benchmark
```

## 🤝 Contributing | 贡献

We welcome contributions to SuperFetch! Please see our [Contributing Guide](docs/developer-guide/contributing.md) for details.

### Development Workflow | 开发工作流

1. Fork the repository | Fork仓库
2. Create a feature branch | 创建功能分支
3. Make your changes | 进行修改
4. Add tests | 添加测试
5. Submit a pull request | 提交拉取请求

## 📄 License | 许可证

This project is licensed under the GNU General Public License v3.0. See [LICENSE](LICENSE) for details.

## 🌟 Roadmap | 路线图

### Version 1.0 (Current) | 版本1.0（当前）
- ✅ Basic system information display
- ✅ Modular architecture
- ✅ Theme support
- ✅ Custom ASCII art
- ✅ Cross-platform compatibility

### Version 2.0 (Planned) | 版本2.0（计划）
- 🔄 Image logo support
- 🔄 More information modules
- 🔄 Plugin system
- 🔄 Configuration GUI
- 🔄 Windows/macOS support

### Future Versions | 未来版本
- 🤖 AI-generated ASCII art
- 🌐 Web-based configuration
- 📱 Mobile device detection
- 🔮 Hardware stress testing integration

## 📞 Support | 支持

- **Documentation**: https://github.com/s12mcOvO/SuperFetch#readme
- **Issues**: https://github.com/s12mcOvO/SuperFetch/issues
- **Discussions**: https://github.com/s12mcOvO/SuperFetch/discussions

---

**SuperFetch** - Fast and beautiful system information tool ⚡