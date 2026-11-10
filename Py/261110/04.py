from html import escape

def show_chart(series, title, y_label, ticks, bars=False):
    """추가 그래프 패키지 없이 노트북 안에 SVG를 표시합니다."""
    colors = ["#205ea6", "#dc650d"]
    width, height = 760, 300
    left, right, top, bottom = 92, 730, 52, 245
    values = np.concatenate([np.asarray(data, dtype=float) for _, data in series])
    low = min(0.0, float(values.min()))
    high = max(low + 1.0, float(values.max()))
    n = len(series[0][1])

    def x(i):
        return left + (right - left) * (i + 0.5) / n

    def y(value):
        return bottom - (bottom - top) * (value - low) / (high - low)

    svg = [f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {width} {height}" width="{width}" role="img" aria-label="{escape(title)}">',
           '<rect width="100%" height="100%" fill="white"/>',
           f'<g font-family="Malgun Gothic, Noto Sans CJK KR, sans-serif" font-size="12" fill="#243247">',
           f'<text x="{left}" y="25" font-size="18" font-weight="bold">{escape(title)}</text>',
           f'<text x="{left}" y="43">{escape(y_label)}</text>']
    for value in np.linspace(low, high, 5):
        yy = y(value)
        svg.append(f'<path d="M{left} {yy}H{right}" stroke="#d8e1eb"/>')
        svg.append(f'<text x="{left-8}" y="{yy+4}" text-anchor="end">{value:,.1f}</text>')
    for i, label in ticks:
        svg.append(f'<text x="{x(i)}" y="{bottom+19}" text-anchor="middle">{escape(str(label))}</text>')
    for j, (name, data) in enumerate(series):
        color = colors[j]
        if bars:
            bar_width = (right - left) / n * 0.6
            for i, value in enumerate(data):
                svg.append(f'<rect x="{x(i)-bar_width/2}" y="{y(value)}" width="{bar_width}" height="{y(0)-y(value)}" fill="{color}"/>')
        else:
            points = " ".join(f"{x(i):.2f},{y(value):.2f}" for i, value in enumerate(data))
            svg.append(f'<polyline points="{points}" fill="none" stroke="{color}" stroke-width="2"/>')
        svg.append(f'<text x="{left+160*j}" y="289" fill="{color}">{escape(name)}</text>')
    svg.append("</g></svg>")
    display({"image/svg+xml": "".join(svg)}, raw=True)
